/*
 * Code author: Jeremy Carleton
 * This code demonstrates what happens when you attempt
 * to print a string with too many characters to fit on
 * the LCD screen.
 * 
 * To see the code being demonstrated, watch
 * session 4 of the workshop series here:
 * https://www.youtube.com/watch?v=7CSGJm4wRhA&list=PLfmzHX29KVv_cbdHYJD3cuvoo_Valq8us&index=5
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
