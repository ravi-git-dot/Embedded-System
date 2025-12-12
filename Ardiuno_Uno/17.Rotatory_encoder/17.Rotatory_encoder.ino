#define clkPin 2     // Rotary encoder CLK pin
#define dtPin 3      // Rotary encoder DT pin
#define swPin 4      // Push-button switch pin

int encoderVal = 0;
static int oldA = HIGH;
static int oldB = HIGH;

void setup() {
  pinMode(clkPin, INPUT);    // CLK pin as input
  pinMode(dtPin, INPUT);     // DT pin as input
  pinMode(swPin, INPUT);     // Switch pin as input

  digitalWrite(swPin, HIGH); // Enable internal pull-up for switch
  Serial.begin(9600);
}

void loop() {
  int change = getEncoderTurn(); // Check if knob rotated (CW or CCW)
  encoderVal = encoderVal + change;

  // If the button is pressed, reset the value to 0
  if (digitalRead(swPin) == LOW) {
    encoderVal = 0;
  }

  Serial.println(encoderVal); // Print updated position
}



// Function: getEncoderTurn()
// Purpose: Detect if the rotary encoder rotated CW or CCW.
// Returns: +1 for one direction, -1 for opposite, 0 for no movement.
int getEncoderTurn(void)
{
  int result = 0;

  int newA = digitalRead(clkPin); // Read CLK
  int newB = digitalRead(dtPin);  // Read DT

  // Check if either A or B changed
  if (newA != oldA || newB != oldB)
  {
    // If CLK changes from HIGH → LOW, it means a step occurred
    if (oldA == HIGH && newA == LOW)
    {
      // Direction is determined by state of DT
      // If DT = HIGH → clockwise, if LOW → counter-clockwise
      result = (oldB * 2 - 1);  
      // oldB = 1 → +1
      // oldB = 0 → -1
    }
  }

  // Store current state for next cycle
  oldA = newA;
  oldB = newB;

  return result; 
}
