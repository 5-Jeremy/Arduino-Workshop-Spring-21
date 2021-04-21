/*
 * Code author: Jeremy Carleton
 * This code gives an example of how practice exercise 1 for session 1 could be solved
 */

void setup() {
  // We only need to establish the serial connection once here
  Serial.begin(9600);
}

void loop() {
  // This while loop prevents the program from doing anything until data can be read
  // from the serial port
  while (!Serial.available());
  // Read a byte from the serial buffer and immediately send an identical byte back.
  // Note that Serial.write() is used to send an identical character back,
  // because Serial.print() will convert a byte to its integer representation
  // and send the characters for that instead
  Serial.write(Serial.read());
}
