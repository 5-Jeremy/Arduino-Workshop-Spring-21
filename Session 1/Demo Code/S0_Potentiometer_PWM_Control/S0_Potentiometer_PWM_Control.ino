/*
 * Code author: Sahas Poyekar
 * This code was used in the demo showing how a
 * potentiometer can be used to control the
 * PWM signal sent by an Arduino board
 */

int ledPin = 10;
int readVal = 0;
int ledVal = 0;
void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  readVal = analogRead(A0);
  ledVal = map(readVal, 0, 1024, 0, 255);
  Serial.println(readVal);
  analogWrite(ledPin, ledVal);
}
