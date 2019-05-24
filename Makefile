CORE:=arduino:avr
FQBN:=arduino:avr:uno
DEFAULT_PORT:=/dev/cu.usbmodem14401
MCU:=ATmega328P

MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CURRENT_DIR := $(notdir $(patsubst %/,%,$(dir $(MAKEFILE_PATH))))

help:
	@perl -nle'print $& if m{^[a-zA-Z_-]+:.*?## .*$$}' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

demo: ## Just a simple demo code
	@echo "make build path=samples/blink"
	@echo "make hex path=samples/test.c"
	@echo "make hex path=samples/test.c && make build path=samples/test"
	
boards: ## Retrieve all boards
	arduino-cli board list

# core:
# 	arduino-cli core search arduino

# mkr1000:
# 	arduino-cli core search mkr1000
# 	arduino-cli core install CORE

# update-index:
# 	arduino-cli core update-index

build: ## Build given sketch
	arduino-cli compile --fqbn $(FQBN) $(path)

deploy: build
	arduino-cli upload -p $(DEFAULT_PORT) --fqbn $(FQBN) $(path)
	rm $(path)/*.elf

## Method 2
hex:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=$(MCU) -c $(path)
	#avr-gcc -DF_CPU=8000000 -mmcu=$(MCU) -o ${shell basename $(path) .c}.elf ${shell basename $(path) .c}.o
	avr-objcopy -O ihex ${shell basename $(path) .c}.o ${shell dirname $(path)}/${shell basename $(path) .c}.hex
	#avr-size -C ${shell basename $(path) .c}.o
	rm ${shell basename $(path) .c}.o

flash: hex
	avrdude -F -V -c arduino -p $(MCU) -P $(DEFAULT_PORT) -b 11520 -U flash:w:${shell dirname $(path)}/${shell basename $(path) .c}.hex

serial: ## CTRL + A + D to detach
	screen $(DEFAULT_PORT) 9600 

try: 
	@echo Hello World!