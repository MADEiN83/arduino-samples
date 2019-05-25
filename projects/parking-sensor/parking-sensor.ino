#define b(num) (1 << num % 8)
#define TRIG 2
#define ECHO 3
#define BUZ 7
#define BUZ_DELAY 100

int distanceTrigger[] = {20, 30, 40, 50, 75, 100};

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Starting"));

  DDRD |= b(BUZ);
  DDRD |= b(TRIG) & ~b(ECHO);
}

void loop()
{
  // Clearing trigger.
  PORTD &= ~b(TRIG);
  _delay_ms(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  PORTD |= b(TRIG);
  _delay_ms(10);
  PORTD &= ~b(TRIG);

  int distance = getDistance();

  // Prints the distance on the Serial Monitor
  Serial.print(F("Distance: "));
  Serial.print(distance);
  Serial.println(F(" cm"));

  buzIfNecessary(distance);
}

// Calculating the distance
int getDistance()
{
  return pulseIn(ECHO, HIGH) * 0.034 / 2;
}

void buzIfNecessary(int distance)
{
  size_t arraySize = sizeof(distanceTrigger) / sizeof(distanceTrigger[0]);

  for (int i = 0; i < arraySize; i++)
  {
    if (canBeep(distance, distanceTrigger[i]))
    {
      tone(BUZ, 1000);
      delayAfterBeep(i);
      noTone(BUZ);
      break;
    }
  }
}

bool canBeep(int distance, int distanceTrigger)
{
  return distance < distanceTrigger;
}

void delayAfterBeep(int i)
{
  delay((i + 1) * BUZ_DELAY);
}