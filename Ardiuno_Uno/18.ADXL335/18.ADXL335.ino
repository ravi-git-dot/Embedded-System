#include <ADXL335.h>

// Define ADXL335 analog pins
#define X_PIN A0
#define Y_PIN A1
#define Z_PIN A2

// Create ADXL335 object
ADXL335 adxl335(X_PIN, Y_PIN, Z_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  float accelerationX, accelerationY, accelerationZ;

  adxl335.getAcceleration(&accelerationX, &accelerationY, &accelerationZ);

  Serial.print(accelerationX);
  Serial.print("\t");
  Serial.print(accelerationY);
  Serial.print("\t");
  Serial.println(accelerationZ);

  delay(500);
}
