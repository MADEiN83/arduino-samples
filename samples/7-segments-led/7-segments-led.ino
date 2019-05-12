uint8_t a = 10;
uint8_t b = 11;
uint8_t c = 12;
uint8_t d = 7;
uint8_t e = 6;
uint8_t f = 9;
uint8_t g = 8;
uint8_t led = 2;
 
void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(led, OUTPUT);
}

bool end = false;
int initialValue = 8;
int timesBeforeEnd = 20;

void loop() {
  if(end) {
    return;
  }
  
  // Off led.
  high(led);
    
  if(initialValue >= 0) {
    sevenSegment_display(a, b, c, d, e, f, g, initialValue);
    initialValue--;
    
    delay(1000);
    return;
  }
  
  if(timesBeforeEnd > 0) {
    low(led);
    delay(50);
    high(led);
    delay(50);

    timesBeforeEnd--;
    return;
  }

  if(timesBeforeEnd <= 0) {
    low(led);
    delay(1000);
    high(led);
    sevenSegment_display(a, b, c, d, e, f, g, -1);
    end = true;
  }
}


/********************************************************************
 ******* 1 bit 7-Segment shield
 ********************************************************************/
void sevenSegment_display(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t nb){
  if(nb < 0 || nb > 9){
    high(a); high(b); high(c); high(d); high(e); high(f); high(g);
    return;
  }
  
  switch(nb){
    case 0: low(a); low(b); low(c); low(d); low(e); low(f); high(g); break;
    case 1: high(a); low(b); low(c); high(d); high(e); high(f); high(g); break;
    case 2: low(a); low(b); high(c); low(d); low(e); high(f); low(g); break;
    case 3: low(a); low(b); low(c); low(d); high(e); high(f); low(g); break;
    case 4: high(a); low(b); low(c); high(d); high(e); low(f); low(g); break;
    case 5: low(a); high(b); low(c); low(d); high(e); low(f); low(g); break;
    case 6: low(a); high(b); low(c); low(d); low(e); low(f); low(g);break;
    case 7: low(a); low(b); low(c); high(d); high(e); high(f); high(g);break;
    case 8: low(a); low(b); low(c); low(d); low(e); low(f); low(g);break;
    case 9: low(a); low(b); low(c); low(d); high(e); low(f); low(g);break;
  }
}

/// <summary>
/// Write a HIGH value to a digital pin.
/// </summary>
/// <param name="pin">The number of the digital pin you want to write (int).</param>
void high(uint8_t pin) {
  digitalWrite(pin, HIGH);
}

/// <summary>
/// Write a LOW value to a digital pin.
/// </summary>
/// <param name="pin">The number of the digital pin you want to write (int).</param>
void low(uint8_t pin) {
  digitalWrite(pin, LOW);
}
