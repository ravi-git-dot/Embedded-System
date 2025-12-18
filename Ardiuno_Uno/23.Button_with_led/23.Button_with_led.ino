#include <Arduino.h>

#define led1 6
#define led2 7
#define led3 8
#define led4 9

#define button1 2
#define button2 3
#define button3 4
#define resetButton 10
#define buzzerPin 5

int resetState;
int b1State;
int b2State;
int b3State;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);
}

void loop()
{
  resetState = digitalRead(resetButton);
  b1State = digitalRead(button1);
  b2State = digitalRead(button2);
  b3State = digitalRead(button3);

  // RESET BUTTON (pressed = LOW)
  if (resetState == HIGH)
  {
    digitalWrite(led4, HIGH);   // System ON indicator
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(500);
    digitalWrite(led4, LOW);
  }

  // BUTTON 1
  if (b1State == HIGH)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    Alarm();
    delay(500);
    digitalWrite(led1, LOW);
  }

  // BUTTON 2
  if (b2State == LOW)
  {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    Alarm();
    delay(500);
    digitalWrite(led2, LOW);
  }

  // BUTTON 3
  if (b3State == HIGH)
  {
    digitalWrite(led3, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led4, LOW);
    Alarm();
    delay(500);
    digitalWrite(led3, LOW);
  }
}

void Alarm()
{
  for (int i = 0; i < 200; i++)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(2);
    digitalWrite(buzzerPin, LOW);
    delay(2);
  }
}
