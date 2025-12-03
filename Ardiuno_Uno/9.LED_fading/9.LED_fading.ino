const int lowestPin = 2;     // First LED connected to pin 2
const int highestPin = 9;    // Last LED connected to pin 9

void setup() {
  // Set all LED pins (2 to 9) as OUTPUT
  for(int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    pinMode(thisPin, OUTPUT);
  }
}

void loop() {

  // Turn LEDs ON one by one from pin 2 to pin 9
  for(int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    digitalWrite(thisPin, HIGH);  // Turn ON the LED
    delay(100);                   // Small delay to see the sequence
  }

  // Turn LEDs OFF one by one from pin 9 back to pin 2
  for(int thisPin = highestPin; thisPin >= lowestPin; thisPin--) {
    digitalWrite(thisPin, LOW);   // Turn OFF the LED
    delay(100);                   // Small delay to see the sequence
  }

  // Turn LEDs ON in reverse direction (pin 9 → pin 2)
  for(int thisPin = highestPin; thisPin >= lowestPin; thisPin--) {
    digitalWrite(thisPin, HIGH);  // Turn ON the LED
    delay(100);
  }

  // Turn LEDs OFF again from pin 2 to pin 9
  for(int thisPin = lowestPin; thisPin <= highestPin; thisPin++) {
    digitalWrite(thisPin, LOW);   // Turn OFF the LED
    delay(100);
  }
}
