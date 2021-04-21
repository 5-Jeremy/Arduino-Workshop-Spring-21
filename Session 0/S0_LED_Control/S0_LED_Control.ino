/*
 * Code author: Jeremy Carleton
 * This code was used in the demo showing how to
 * control an LED with a button.
 * 
 * To see the code being demonstrated, watch
 * session 0 of the workshop series here:
 * https://www.youtube.com/watch?v=xH92LeNyk5w&list=PLfmzHX29KVv_cbdHYJD3cuvoo_Valq8us&index=2
 */

void setup()
{
  pinMode(7, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  // Because the input to pin 2 is always connected to
  // the pullup resistor (via the pushbutton), we recieve 
  // high voltage on pin 2 when the button is up.
  // When the button is down, the wire connecting pin 2 to
  // the pullup resistor is grounded, so we recieve
  // low voltage on pin 2. For this reason, we take the
  // complement of the result of digitalRead(2) and 
  // only turn on the LED when that is true.
  if (!digitalRead(2)) {
	digitalWrite(7,HIGH);
  }
  else {
    digitalWrite(7,LOW);
  }
}
