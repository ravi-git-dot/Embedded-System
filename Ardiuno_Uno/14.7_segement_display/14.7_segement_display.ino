// 7-segment display segment pins
const int a  = 7;
const int b  = 6;
const int c  = 5;
const int d  = 11;
const int e  = 10;
const int f  = 8;
const int g  = 9;
const int dp = 4;

// --------------------------------------------------

void setup() {

  // Set all segment pins as OUTPUT
  for (int thisPin = 4; thisPin <= 11; thisPin++) {
    pinMode(thisPin, OUTPUT);   // FIXED: removed invalid [i]
  }
}

// --------------------------------------------------
// Turn OFF all segments before drawing next number
void clearDisplay() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(dp, LOW);
}

// --------------------------------------------------

void loop() {

  digital_1();
  delay(1000);
  digital_2(); 
  delay(1000);
  digital_3(); 
  delay(1000);
  digital_4(); 
  delay(1000);
  digital_5(); 
  delay(1000);
  digital_6(); 
  delay(1000);
  digital_7(); 
  delay(1000);
  digital_8(); 
  delay(1000);
  digital_9(); 
  delay(1000);
}

// NUMBER PATTERNS

// Number 1: segments b, c
void digital_1(void) {
  clearDisplay();
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

// Number 2: a, b, g, e, d
void digital_2(void) {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
}

// Number 3: a, b, c, d, g
void digital_3(void) {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(g, HIGH);
}

// Number 4: f, g, b, c  (CORRECTED: removed wrong 'd')
void digital_4(void) {
  clearDisplay();
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

// Number 5: a, f, g, c, d
void digital_5(void) {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

// Number 6: a, f, e, g, c, d
void digital_6(void) {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

// Number 7: a, b, c
void digital_7(void) {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

// Number 8: all segments ON
void digital_8(void) {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

// Number 9: a, b, c, d, f, g
void digital_9(void) {
  clearDisplay();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
