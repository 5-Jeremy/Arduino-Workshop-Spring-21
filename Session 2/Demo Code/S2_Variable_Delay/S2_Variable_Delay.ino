/*
 * Code author: Jeremy Carleton
 * This code was used in the demo showing how
 * delays can be used on an LED circuit
 */

int delayVal;
void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  delayVal = 1000;
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(delayVal); // Wait delayVal millisecond(s)
  digitalWrite(2, LOW);
  delay(delayVal); // Wait delayVal millisecond(s)
  // Update delayVal by reading a number from the serial
  // monitor if possible
  if (Serial.available()) {
    delayVal = Serial.parseInt();
  }
  // Print current delay amount
  Serial.println(delayVal);
}
