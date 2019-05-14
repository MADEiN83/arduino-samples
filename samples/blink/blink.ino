#include <avr/io.h>     // .h contenant les registres SFR
#include <util/delay.h> // .h contenant les fonctions de délai

int main(void)
{
  DDRB |= (1 << PIN5); // pinMode OUTPUT

  for (;;)
  {                       // Équivalent loop()
    PORTB |= (1 << PIN5); // digitalWrite HIGH
    _delay_ms(500);
    PORTB &= ~(1 << PIN5); // digitalWrite LOW
    _delay_ms(500);
  }
}