#include <avr/io.h>     // .h contenant les registres SFR
#include <util/delay.h> // .h contenant les fonctions de délai

int bitwise(int pin)
{
  return 1 << (pin % 8);
}

int main(void)
{
  int p = bitwise(13);
  DDRB |= p; // pinMode OUTPUT

  for (;;)
  {                       // Équivalent loop()
    PORTB |= p; // digitalWrite HIGH
    _delay_ms(200);
    PORTB &= ~p; // digitalWrite LOW
    _delay_ms(200);
  }
}
