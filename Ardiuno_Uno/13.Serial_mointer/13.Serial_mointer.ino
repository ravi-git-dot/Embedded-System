// Define pins for LEDs
#define greenPin 2      // Green LED on pin 2
#define yellowPin 3     // Yellow LED on pin 3
#define redPin 4        // Red LED on pin 4

String comData = "";    // This variable stores the text received from Serial Monitor

void setup() {

  // Set LED pins as output
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
  
  // Display instructions to the user
  Serial.println("Type: red / yellow / green");
}

void loop() {

  // Check if user typed something in Serial Monitor
  if (Serial.available() > 0) {

    // Read the entire message until Enter key
    comData = Serial.readStringUntil('\n');

    // Remove unwanted spaces or newlines
    comData.trim();

    // Print what user typed
    Serial.println("You entered: " + comData);
  }

  // If user types “red”, turn ON red LED
  if (comData == "red") {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
  }

  // If user types “yellow”, turn ON yellow LED
  else if (comData == "yellow") {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
  }

  // If user types “green”, turn ON green LED
  else if (comData == "green") {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  }
}
