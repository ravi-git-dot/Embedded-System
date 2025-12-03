const int redPin = 11;     // Red LED connected to PWM pin 11
const int greenPin = 10;   // Green LED connected to PWM pin 10
const int bluePin = 9;     // Blue LED connected to PWM pin 9

void setup() {
  // Set all RGB LED pins as output because we are controlling brightness
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  // Show pure red color
  color(255, 0, 0);
  delay(1000);    // wait 1 second

  // Show pure green color
  color(0, 255, 0);
  delay(1000);

  // Show pure blue color
  color(0, 0, 255);
  delay(1000);

  // Show orange-ish color
  color(237, 109, 0);
  delay(1000);

  // Show gold/yellow color
  color(255, 215, 0);
  delay(1000);

  // Show forest green
  color(34, 139, 34);
  delay(1000);

  // Show deep blue
  color(0, 0, 255);
  delay(1000);

  // Show dark blue navy color
  color(0, 46, 90);
  delay(1000);

  // Show purple
  color(128, 0, 128);
  delay(1000);
}

// This function sets the brightness of each RGB LED channel
// Values range from 0 (OFF) to 255 (FULL BRIGHTNESS)
void color(unsigned char red, unsigned char green, unsigned char blue)
{
  analogWrite(redPin, red);     // Control red brightness
  analogWrite(greenPin, green); // Control green brightness
  analogWrite(bluePin, blue);   // Control blue brightness
}
