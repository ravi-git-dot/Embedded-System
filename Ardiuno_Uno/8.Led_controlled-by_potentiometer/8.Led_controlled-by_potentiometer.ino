const int ledPin = 9;        // led connect to Pin 9
const int analogPin = A0;    // Analog Pin is connect ot A0

int inputValue = 0;         // intialized the input value is zero
int outputValue = 0;        // intialized the output value is zero

void setup() {
  pinMode(ledPin,  OUTPUT);  // set the led as an output

}

void loop() {
  // Read the analog value from the potentiometer (0 to 1023)
  inputValue = analogRead(analogPin);

  // Convert the analog value (0–1023) to PWM value (0–255)
  outputValue = map(inputValue, 0, 1023, 0, 255);

  // Send the PWM value to the LED to control brightness
  analogWrite(ledPin, outputValue);

  delay(10);  // Small delay to make the transition smooth

}
