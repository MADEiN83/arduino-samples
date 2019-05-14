CORE:=arduino:avr
FQBN:=arduino:avr:uno
DEFAULT_PORT:=/dev/cu.usbmodem14401

MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CURRENT_DIR := $(notdir $(patsubst %/,%,$(dir $(MAKEFILE_PATH))))

help:
	@perl -nle'print $& if m{^[a-zA-Z_-]+:.*?## .*$$}' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

demo: ## Just a simple demo code
	@echo "make build path=samples/blink"
	
boards: ## Retrieve all boards
	arduino-cli board list

core:
	arduino-cli core search arduino

mkr1000:
	arduino-cli core search mkr1000
	arduino-cli core install CORE

update-index:
	arduino-cli core update-index

build: ## Build given sketch
	arduino-cli compile --fqbn $(FQBN) ${path}

upload: build ## Upload given sketch to arduino card
	arduino-cli upload -p $(DEFAULT_PORT) --fqbn $(FQBN) ${path}