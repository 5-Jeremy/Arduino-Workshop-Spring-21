/*
 * Code author: Jeremy Carleton
 * This code gives an example of how practice exercise 2 for session 1 could be solved
 */
 
// returnNum stores the sum of the integers
int returnNum;

void setup() {
  Serial.begin(9600);
  returnNum = 0;
}

void loop() {
  while (!Serial.available());
  // Serial.parseInt() reads bytes from the input buffer and stops after reading the first complete string of
  // consecutive digits, which it interprets as an integer in order to return that integer value
  int recievedNum = Serial.parseInt();
  // The newline at the end is interpreted by Serial.parseInt() as a zero, so this tells us to stop adding.
  // Note that if the number zero is included in the middle of the series of integers, it will cause the integers
  // on either side of it to be added together independently
  if (recievedNum == 0) {
    Serial.println(returnNum);
    returnNum = 0;
  }
  else {
    returnNum = returnNum + recievedNum;
  }
}
