const int NBrLEDs = 8;
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int photoResistor = A0;

#define Bright_Light 800   // LDR threshold

int sensorValue = 0;
int ledLevel = 0;

void setup()
{
  for (int led = 0; led < NBrLEDs; led++)
  {
    pinMode(ledPins[led], OUTPUT);
  }
}

void loop()
{
  // Read LDR value
  sensorValue = analogRead(photoResistor);
  
  if(sensorValue > Bright_Light)
  {
    for (int led = 0; led< NBrLEDs; led++)
    {
      digitalWrite(ledPins[led], LOW);
    }
  }
  else
  {
    
    // Convert sensor value to LED count
    ledLevel = map(sensorValue, 0, 1023, NBrLEDs, 1);

    // saftey clamp
    ledLevel = constrain(ledLevel, 0, NBrLEDs);

    // Turn LEDs ON/OFF
    for (int led = 0; led < NBrLEDs; led++)
    {
      if (led < ledLevel)
      {
        digitalWrite(ledPins[led], HIGH);
      }
      else
      {
        digitalWrite(ledPins[led], LOW);
      }
    }
  }

  delay(5);
}
