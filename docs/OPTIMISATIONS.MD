# optimisations w/ avc-r

# main & loop

Instead of:

```c
void start() {
    // Setup goes here.
}

void loop() {
    // Loop logic goes here.
}
```

I prefer:

```c

int main() {
    // Setup goes here.

    for(;;){
        // Loop logic goes here.
    }

    return 0;
}
```

# delay

Instead of:

```c
void start() {
    // Setup goes here.
}

void loop() {
    delay(1000);
}
```

I prefer:

```c

int main() {
    // Setup goes here.

    for(;;){
        _delay_ms(1000);
    }

    return 0;
}
```

# pinMode

Instead of:

```c
int pin = 3;

void start() {
    pinMode(pin, OUTPUT);
}

void loop() {
    // Loop logic goes here.
}
```

I prefer:

```c
int pin = 3;

int main() {
    DDRD |= 1 << pin % 8;

    for(;;){
        // Loop logic goes here.
    }

    return 0;
}
```

# digitalWrite

Instead of:

```c
int pin = 3;

void start() {
    // Setup goes here.
}

void loop() {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
}
```

I prefer:

```c
int pin = 3;

int main() {
    // Setup goes here.

    for(;;){
        PORTD |= 1 << pin % 8;
        _delay_ms(500);
        PORTD &= ~(1 << pin % 8);
    }

    return 0;
}
```
