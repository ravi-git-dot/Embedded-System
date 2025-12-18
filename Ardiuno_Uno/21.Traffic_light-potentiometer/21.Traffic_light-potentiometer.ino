#define redPin 7     // Red LED connected to pin 7
#define yellowPin 8  // Yellow LED connected to pin 8
#define greenPin 9   // Green LED connected to pin 9

#define potPin A0    // Potentiometer connected to A0
#define swPin 6      // Push button pin

// Stores potentiometer value
int potValue = 0;

// Stores current traffic light state
int state = 0;

// Time values for traffic light
int shortPeriod = 1000;    // Short delay (1 second)
int longPeriod = 1000;     // Long delay (controlled by potentiometer)

// Target delay for current state
int targetCount = 1000;

// Counter used as a timer
int count = 0;

void setup() {

  pinMode(potPin, INPUT);
  pinMode(swPin, INPUT_PULLUP);

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
  Serial.println(analogRead(A0));

}

void loop() {

  count++;   // Increment counter every loop (used for timing)

  // Read potentiometer value (0–1023)
  potValue = analogRead(potPin);

  // Map potentiometer value to time (1s – 10s)
  longPeriod = map(potValue, 0, 1023, 1000, 10000);

  // Check if button is pressed
  if (digitalRead(swPin) == LOW)
  {
    setLights(HIGH, HIGH, HIGH);   // Turn ON all LEDs
  }
  else
  {
    // Check if delay time is completed
    if (count == targetCount)
    {
      setState();     // Change traffic light state
      count = 0;      // Reset timer
    }
  }

  delay(1);   // Small delay for stable timing
}

// ================= TRAFFIC LIGHT STATES =================
void setState(void)
{
  // State 0 → Red ON
  if (state == 0)
  {
    setLights(HIGH, LOW, LOW);
    targetCount = longPeriod;
    state = 1;
  }

  // State 1 →  Yellow ON
  else if (state == 1)
  {
    setLights(LOW, HIGH, LOW);  
    targetCount = shortPeriod;
    state = 2;
  }

  // State 2 → Green ON
  else if (state == 2)
  {
    setLights(LOW, LOW, HIGH);
    targetCount = longPeriod;
    state = 3;
  }

  // State 3 → Yellow ON
  else if (state == 3)
  {
    setLights(LOW, HIGH, LOW);
    targetCount = shortPeriod;
    state = 0;
  }
}
// ================= LED CONTROL FUNCTION =================
void setLights(int r, int y, int g)
{
  digitalWrite(redPin, r);
  digitalWrite(yellowPin, y);
  digitalWrite(greenPin, g);
}

