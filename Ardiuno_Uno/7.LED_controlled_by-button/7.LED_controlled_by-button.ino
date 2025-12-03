const int ledPin = 8;    // LED connected to pin 3
const int keyPin = 12;   // Button connected to pin 12

void setup() {
  pinMode(ledPin, OUTPUT); // set the led as an output
  pinMode(keyPin, INPUT);  // set the button as intput signal

}

void loop() {

  // Read the button state (HIGH or LOW)
  int buttonState = digitalRead(keyPin);

  // If the button is pressed (HIGH), turn ON the LED
  if(buttonState == LOW)
  {
    digitalWrite(ledPin, HIGH); 
  }
  // Otherwise turn OFF the LED
  else
  {
    digitalWrite(ledPin, HIGH);
  }      

}
