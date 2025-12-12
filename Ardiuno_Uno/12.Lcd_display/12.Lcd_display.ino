#include <LiquidCrystal_I2C.h>    // Include the LCD library

// Two messages to scroll on LCD
char message1[] = "Hello RaviRaj";        // First message
char message2[] = "Welcome to House";     // Second message

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initialize 16x2 I2C LCD


int tin = 500;                            // Delay time for scrolling effect

void setup() {
  lcd.init();          // Start LCD
  lcd.backlight();     // Turn ON backlight
  lcd.begin(16, 2);                       // Initialize 16x2 LCD display
}

void loop() {

  //Scroll First Message on Row 0
  lcd.setCursor(15, 0);                   // Start at far right of row 0
  for (int i = 0; message1[i] != '\0'; i++) {
    lcd.scrollDisplayLeft();              // Scroll text to left
    lcd.print(message1[i]);               // Print one character at a time
    delay(tin);                           // Wait
  }

  lcd.clear();                            // Clear display


  //Scroll Second Message on Row 1
  lcd.setCursor(15, 1);                   // Start at far right of row 1
  for (int i = 0; message2[i] != '\0'; i++) {
    lcd.scrollDisplayLeft();              // Scroll text to left
    lcd.print(message2[i]);               // Print one character at a time
    delay(tin);                           // Wait
  }

  lcd.clear();                            // Clear display
}
