// Ultrasonic Sensor Pins
int trigPin = 12;   // This pin sends the trigger signal
int echoPin = 11;   // This pin receives the echo signal

long duration;       // Time taken for the echo to return
long distance;       // Calculated distance based on time

void setup() {
  Serial.begin(9600);  // Start the Serial Monitor at 9600 baud rate

  // Let Arduino know which pins are input and output
  pinMode(trigPin, OUTPUT);  // Trigger pin will send pulses
  pinMode(echoPin, INPUT);   // Echo pin will listen for the reflected pulse
}

void loop() {

  // Before sending the trigger pulse, make sure the trigger pin is LOW.
  // This creates a clean signal.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);

  // Send a short 10 microsecond HIGH pulse.
  // This tells the ultrasonic sensor to send out the sound wave.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Wait for the echo pin to go HIGH, meaning the sound has returned.
  // The pulseIn function measures how long that HIGH signal lasted.
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into distance.
  // Speed of sound is ~340 m/s, which is 0.034 cm per microsecond.
  // Divide by 2 because the wave travels to the object and back.
  distance = (duration * 0.0343) / 2;

  // Print the distance to the Serial Monitor in centimeters.
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // A small delay to make the readings stable and readable
  delay(100);
}
