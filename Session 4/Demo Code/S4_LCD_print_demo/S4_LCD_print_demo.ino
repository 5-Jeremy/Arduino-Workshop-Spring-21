/*
 * Code author: Jeremy Carleton
 * This code demonstrates how to use lcd.print to display full
 * words on the LCD
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
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("This");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("message");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("is");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("printed");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("in");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("parts.");
  delay(1000);
  lcd.clear();
}
