uint8_t led = 6;
uint8_t switchPin = 5;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);

  
Serial.begin(9600);
}

void loop() {
  
Serial.write("oui");
  int isPressed = digitalRead(switchPin) == 0;

  digitalWrite(led, isPressed ? LOW : HIGH);
  delay(100);
}
