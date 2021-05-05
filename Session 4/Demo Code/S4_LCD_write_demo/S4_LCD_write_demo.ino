/*
 * Code author: Jeremy Carleton
 * This code demonstrates how lcd.write can be called
 * repeatedly to display a longer message on the LCD,
 * since the cursor is moved automatically
 */

// Include the library code:
#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  for (int i = 0; i < 16; ++i) {
    lcd.write('0' + (i % 10));
  }
}

void loop() {
  // No need to do anything here
}
