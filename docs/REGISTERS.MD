# registers (ATmega328P)

## DDR (Data Direction Register)

Corresponds to the pin that is specified by `pinMode()`. If the bit of corresponding DDR is `0`, the pin is configured as an `input`. If the bit of DDR is `1`, the pin is configured as an `output`.

- DDRB: Pins [8...13]
- DDRC: Pins [A0...A5]
- DDRD: Pins [0...7]

## PORT

The `digitalRead()` returns if the specified pin is `HIGH` or `LOW`. If the value of the corresponding bit of the register is `1` it returns `HIGH`, if `0` it returns `LOW`.

- PORTB: Pins [8...13]
- PORTC: Pins [A0...A5]
- PORTD: Pins [0...7]

## ADMUX (ADC Multiplexer Selection Register)

The `analogRead()` reads the value from analog pin using analog-digital(AD) converter.

| BIT  | 7     | 6     | 5     | 4   | 3    | 2    | 1    | 0    |
| ---- | ----- | ----- | ----- | --- | ---- | ---- | ---- | ---- |
| name | REFS1 | REFS0 | ADLAR | -   | MUX3 | MUX2 | MUX1 | MUX0 |

The `REFS0` and `REFS1` set the reference voltage. The meanings of the combination of these bits are shown in the next table.

| REFS1 | REFS0 | Meanings                                                | Argument of analogReference() |
| ----- | ----- | ------------------------------------------------------- | ----------------------------- |
| 0     | 0     | Voltage applied to AREF pin                             | EXTERNAL(0)                   |
| 0     | 1     | Default referece voltage(5V in case of Arduino Uno)     | DEFAULT(1)                    |
| 1     | 0     | Reserved                                                | -                             |
| 1     | 1     | Internal reference voltage(1.1V in case of Arduino Uno) | INTERNAL(3)                   |

The ADLAR detemins the presentation of the ADC conversion result. If it is 1, the ADC conversion result is left adjusted. If 0, right adjusted. It is set to 0, right adjusted, by the Arduino software.

MUX0 to MUX3 selects the analog pin.

If MUX3...MUX0 is 1000, it reads the value from an internal temperature sensor. But the ability to read internal temperature sensor is dsiabled in Arduino software.

## ADCSRA (ADC Control and Status Register A)

todo

## ADCH,ADCL

todo

## TCCR0A,TCCR0B

todo

## TCNT0

todo

## OCR0A, OCR0B

todo

## TIMSK0

todo

## TIFR ０

todo

## SREG

todo
