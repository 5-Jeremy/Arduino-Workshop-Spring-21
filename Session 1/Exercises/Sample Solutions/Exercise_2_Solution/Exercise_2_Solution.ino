// returnNum stores the sum of the integers
int returnNum;

void setup() {
  Serial.begin(9600);
  returnNum = 0;
}

void loop() {
  while (!Serial.available());
  // On each execution of loop(), receivedNum gets another integer value from the serial buffer, and if the value
  // is nonzero it is added onto returnNum
  int receivedNum = Serial.parseInt();
  // The zero at the end tells us to stop adding.
  // Note that if the number zero is included in the middle of the series of integers, it will cause the integers
  // on either side of it to be added together independently
  if (receivedNum == 0) {
    Serial.println(returnNum);
    returnNum = 0;
  }
  else {
    returnNum = returnNum + receivedNum;
  }
}
