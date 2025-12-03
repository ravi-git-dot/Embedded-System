const int analogInPin = A0;  // A0 pin is used for the Potentiometer

int sensorDigitalValue = 0;      // digital value from ADC (0–1023)
float sensorVoltageValue = 0.0;  // calculated voltage

void setup() {
  Serial.begin(9600); // initialize serial
}

void loop() {
  // read analog value (0–1023)
  sensorDigitalValue = analogRead(analogInPin);

  // convert to voltage
  sensorVoltageValue = (sensorDigitalValue * 5.0) / 1023.0;

  // print both values
  Serial.print("Digital Value = ");
  Serial.print(sensorDigitalValue);
  Serial.print("\t Voltage = ");
  Serial.println(sensorVoltageValue);

  delay(200); // wait for stable ADC reading
}
