/*
 * Code author: Jonathan Tsai
 * This code gives an example of how practice exercise 2 
 * for session 3 could be solved. Note that it is
 * intended to be used with the circuit provided as an 
 * image in the readme for this sample solution
 */

#include <Servo.h>

Servo myservo;  
int pinL = A0;  
int valL;    
int angleL;
int pinR = A1;  
int valR;
int angleR;
int refL;
int refR;
void setup() {
  myservo.attach(5);
  refL = analogRead(pinL);
  refR = analogRead(pinR);
}

void loop() { //(0,180)--> (left/closed,right/open)
  valL = analogRead(pinL);
  valR = analogRead(pinR);
  valL= map(valL, 325, 1023, 0, 180);
  valR= map(valR, 325, 1023, 0, 180);
  if(valL >(valR+5)){ //if darker outside
    myservo.write(0);                 
    delay(15);  
  }else if(valR >(valL+5)){//if brighter outside
    myservo.write(180-(valL*180)/valR);                 
    delay(15);
  }else{
    delay(15);
  }
}
