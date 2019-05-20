# arduino-samples

## bitwise - shift Operators

```
int a = 0000000000000001

a << 1 = 0000000000000010
a << 2 = 0000000000000100
a << 3 = 0000000000001000
```

## bitwise - pins

https://playground.arduino.cc/Code/BitMath/

https://github.com/osx-cross/homebrew-avr

https://www.instructables.com/id/AVR-Programming-with-Arduino-AVRdude-and-AVR-gcc/

http://www.nongnu.org/avr-libc/

http://gcc.gnu.org/wiki/avr-gcc

https://garretlab.web.fc2.com/en/arduino/inside/arduino/wiring_digital.c/pinMode.html

https://github.com/arduino/ArduinoCore-samd/blob/master/cores/arduino/wiring_digital.c

|     | BYTES      | TYPE   | CALCUL        |
| --- | ---------- | ------ | ------------- |
| 1   | 0x00000010 | `DDRD` | 1 << (1 % 8)  |
| 2   | 0x00000100 | `DDRD` | 1 << (2 % 8)  |
| 3   | 0x00001000 | `DDRD` | 1 << (3 % 8)  |
| 4   | 0x00010000 | `DDRD` | 1 << (4 % 8)  |
| 5   | 0x00100000 | `DDRD` | 1 << (5 % 8)  |
| 6   | 0x01000000 | `DDRD` | 1 << (6 % 8)  |
| 7   | 0x10000000 | `DDRD` | 1 << (7 % 8)  |
| 8   | 0x00000001 | `DDRB` | 1 << (8 % 8)  |
| 9   | 0x00000010 | `DDRB` | 1 << (9 % 8)  |
| 10  | 0x00000100 | `DDRB` | 1 << (10 % 8) |
| 11  | 0x00001000 | `DDRB` | 1 << (11 % 8) |
| 12  | 0x00010000 | `DDRB` | 1 << (12 % 8) |
| 13  | 0x00100000 | `DDRB` | 1 << (13 % 8) |

## bitwse - pin mode

- DDRD: digital pins 7, 6, 5, 4, 3, 2, 1, 0
- DDRB: digital pins -, -, 13 ,12, 11, 10, 9, 8

```c
DDRD |= 1 << (1 % 8); // 00000010 - set pin "1" to OUTPUT, other pins are INPUT
...
DDRD |= 1 << (6 % 8); // 01000000 - set pin "6" to OUTPUT, other pins are INPUT
...
DDRB |= 1 << (13 % 8); // 00100000 - set pin "13" to OUTPUT, other pins are INPUT
```

## bitwse - pin mode

- PORTD: digital pins 7, 6, 5, 4, 3, 2, 1, 0
- PORTB: digital pins -, -, 13 ,12, 11, 10, 9, 8

```c
PORTD |= 00010000; // turns on "4" - equivalent digitalWrite(4, HIGH)
PORTD |= 10010000; // turns on "4" & "7" - equivalent digitalWrite(4 | 7, HIGH)
...
PORTB |= 00010000; // turns on "12" - equivalent digitalWrite(12, HIGH)
PORTB |= 00110101; // turns on "13" & "12" & "10" & "8" - equivalent digitalWrite(13 | 12 | 10 | 8, HIGH)
```

## docker - arduino environment

```bash
docker build -t arduino .
docker run -it -v $(pwd)/projects:/usr/src/app arduino bash
```

All-in-one

```bash
docker build -t arduino && docker run -it -v $(pwd)/projects:/usr/src/app arduino bash
```
