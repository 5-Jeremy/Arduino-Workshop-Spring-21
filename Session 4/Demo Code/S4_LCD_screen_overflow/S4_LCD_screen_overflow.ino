/*
 * Code author: Jeremy Carleton
 * This code demonstrates what happens when you attempt
 * to print a string with too many characters to fit on
 * the LCD screen.
 */

// Include the library code:
#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("This message is printed all at once");
}

void loop() {
}
