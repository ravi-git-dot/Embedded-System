#define redPin 7     // Red LED connected to pin 7
#define yellowPin 8  // Yellow LED connected to pin 8
#define greenPin 9   // Green LED connected to pin 9

#define clkPin 2     // Encoder clock pin
#define dtPin 3      // Encoder data pin
#define swPin 6      // Encoder push button pin

// Stores encoder value (not used yet)
int encoder_val = 0;

// Stores current traffic light state
int state = 0;

// Time values for traffic light
int shortPeriod = 1000;    // Short delay (1 second)
int longPeriod = 1000;     // Long delay (adjustable by encoder)

// Target delay for current state
int targetCount = 1000;

// Counter used as a timer
int count = 0;

void setup() {

  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {

  count++;                         // Increment counter every loop (used for timing)

  int change = getEncoderTurn();   // Read encoder rotation
  longPeriod = longPeriod + change * 1000;

  // Check if encoder button is pressed
  if (digitalRead(swPin) == LOW)
  {
    setLights(HIGH, HIGH, HIGH);
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

  delay(1);  // Small delay to slow down loop
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

  // State 1 → Red + Yellow ON
  else if (state == 1)
  {
    setLights(HIGH, HIGH, LOW);
    targetCount = longPeriod;
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
    targetCount = longPeriod;
    state = 0;
  }
}

void setLights(int r, int y, int g)
{
  digitalWrite(redPin, r);
  digitalWrite(yellowPin, y);
  digitalWrite(greenPin, g);
}


int getEncoderTurn(void)
{
  static int oldA = HIGH;
  static int oldB = HIGH;

  int result = 0;

  int newA = digitalRead(clkPin);
  int newB = digitalRead(dtPin);

  if (newA != oldA)
  {
    if (newA == LOW)
    {
      result = (newB == HIGH) ? 1 : -1;
    }
  }

  oldA = newA;
  oldB = newB;

  return result;
}
