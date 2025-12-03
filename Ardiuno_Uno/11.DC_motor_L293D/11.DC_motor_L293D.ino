int motorIn1 = 9;      // Motor control pin 1 connected to pin 9 (PWM supported)
int motorIn2 = 12;     // Motor control pin 2 connected to pin 12 

void setup() {
  pinMode(motorIn1, OUTPUT);  // Set pin 9 as output to control motor direction/speed
  pinMode(motorIn2, OUTPUT);  // Set pin 12 as output to control motor direction/speed
}

void loop() {
  clockwise(200);      // Run motor clockwise at speed value 200 (0–255)
  delay(200);          // Wait 200 milliseconds

  counterclockwise(200);  // Run motor counterclockwise at speed value 200 (0–255)
  delay(200);             // Wait 200 milliseconds
}

void clockwise(int Speed) {
  analogWrite(motorIn1, Speed);  // Apply PWM to motorIn1 → motor rotates clockwise
  analogWrite(motorIn2, 0);      // Set motorIn2 LOW to allow CW rotation
}

void counterclockwise(int Speed) {
  analogWrite(motorIn1, 0);      // Set motorIn1 LOW to allow CCW rotation
  analogWrite(motorIn2, Speed);  // Apply PWM to motorIn2 → motor rotates counterclockwise
}
