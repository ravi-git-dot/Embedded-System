int ledPin = 7;
int ldrPin = A0;
int buzzerPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);

  if (ldrValue > 600)
  {   // adjust threshold
    digitalWrite(buzzerPin, HIGH);  // buzzer ON
    digitalWrite(ledPin, HIGH);     // Light ON
  }
  else 
  {
    digitalWrite(buzzerPin, LOW);   // buzzer OFF
    digitalWrite(ledPin, LOW);      // Light OFF
  }

  delay(200);
}
