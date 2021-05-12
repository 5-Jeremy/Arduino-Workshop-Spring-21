/*
 * Code author: Jonathan Tsai
 * This code shows how the reading from
 * a photoresistor can be directly applied
 * to control a servo using the built-in
 * map() function and the servo library.
 * 
 * To see the code being demonstrated, watch
 * session 3 of the workshop series here:
 * https://www.youtube.com/watch?v=5ZHbrZyIhhQ&list=PLfmzHX29KVv_cbdHYJD3cuvoo_Valq8us&index=4
 */

#include <Servo.h>

Servo myservo;
int pinIn = 0;
int val;

void setup() {
  myservo.attach(5);
}

void loop() {
  val = analogRead(pinIn);
  val = map(val, 0, 1023, 0, 180);
  myservo.write(val);
  delay(15);
}
