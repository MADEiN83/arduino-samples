uint8_t r = 1;
uint8_t y = 2;
uint8_t g = 3;

void setup() {
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  digitalWrite(r, LOW);
  digitalWrite(y, HIGH);
  digitalWrite(g, HIGH);

  delay(4000);
  
  digitalWrite(r, HIGH);
  digitalWrite(y, LOW);
  digitalWrite(g, HIGH);

  delay(2000);
  
  digitalWrite(r, HIGH);
  digitalWrite(y, HIGH);
  digitalWrite(g, LOW);

  delay(3000);
}
