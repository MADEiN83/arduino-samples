uint8_t led1 = 6;
uint8_t led2 = 5;
uint8_t potentiometer = A3;

void setup() {
  Serial.begin(9600);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  long value = analogRead(potentiometer);

  analogWrite(led1, value / 4);
  analogWrite(led2, 1023 - (value / 4));
}
