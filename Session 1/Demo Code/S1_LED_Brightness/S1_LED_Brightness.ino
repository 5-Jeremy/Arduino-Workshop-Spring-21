/*
 * Code author: Sahas Poyekar
 * This code was used in the demo showing how to
 * use PWM signals to control the brightness of an
 * LED
 * 
 * To see the code being demonstrated, watch
 * session 1 of the workshop series here:
 * https://www.youtube.com/watch?v=7tQ5AFlFzKk&list=PLfmzHX29KVv_cbdHYJD3cuvoo_Valq8us&index=2
 */

int ledPin = 10;
void setup()
{
  pinMode(ledPin, OUTPUT);
}
void loop()
{
  analogWrite(ledPin, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(ledPin, 50);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(ledPin, 100);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(ledPin, 150);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(ledPin, 255);
  delay(1000); // Wait for 1000 millisecond(s)
}
