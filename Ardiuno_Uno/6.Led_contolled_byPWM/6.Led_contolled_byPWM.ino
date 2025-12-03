# define ledPin 9  // LEd connect to PWM pin 9

void setup() {
  pinMode(ledPin, OUTPUT); // set the led as an output

}

void loop() {

  for(int a =0; a<= 255; a++)
  {
    // Fade the LED from OFF (0) to full brightness (255)
    analogWrite(ledPin, a);    // write the PWM value to led
    delay(20);                 // small delay  for smooth fading
  }
  for(int a =255; a >= 0; a--)
  {
    // Fade the LED from full brightness back down to OFF
    analogWrite(ledPin, a);   // write the PWM to led
    delay(20);               //  small delay for smotthe fading
  }
  delay(500);  // Wait 0.5 seconds before the next fade cycle
}