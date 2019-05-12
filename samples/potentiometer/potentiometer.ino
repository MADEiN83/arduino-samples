uint8_t led = 6;
uint8_t potentiometer = A3;

void setup() {
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
}

void loop() {
  long value = analogRead(potentiometer);
  Serial.println(1023 - (value / 4));

  analogWrite(led, 1023 - (value / 4));
}
