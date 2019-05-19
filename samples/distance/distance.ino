int echo = 10;
int trig = 11;

long duration;
int distance;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting");

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop()
{
  // Clearing trigger.
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echo, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);
}
