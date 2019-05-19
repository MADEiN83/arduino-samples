int pin = A0;
int limit = 300;

void setup()
{
    Serial.begin(9600);
    pinMode(13, OUTPUT);
}

void loop()
{
    int value = analogRead(pin);
    value = map(value, 1023, 0, 0, 100);

    Serial.print("Mositure : ");
    Serial.print(value);
    Serial.println("%");

    if (value > 50)
    {
        digitalWrite(13, HIGH);
    }
    else
    {
        digitalWrite(13, LOW);
    }

    delay(200);
}
