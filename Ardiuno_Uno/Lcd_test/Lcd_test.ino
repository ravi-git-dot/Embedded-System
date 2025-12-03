#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   // Your confirmed address

void setup() {
  lcd.init();         // Initialize LCD
  lcd.backlight();    // Turn on backlight
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("LCD Works!");

  lcd.setCursor(0,1);
  lcd.print("Hello Ravi");
}

void loop() {
}
