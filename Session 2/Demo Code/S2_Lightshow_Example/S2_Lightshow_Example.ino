/*
 * Code author: Jeremy Carleton
 * This code is a very simple example
 * of how to create a looping lightshow
 * for the custom lightshow project.
 * 
 * To see the code being demonstrated on a physical circuit, watch
 * session 3 of the workshop series here:
 * https://www.youtube.com/watch?v=5ZHbrZyIhhQ&list=PLfmzHX29KVv_cbdHYJD3cuvoo_Valq8us&index=5
 */

#define TR_PIN 2
#define TC_PIN 6
#define TL_PIN 5
#define MR_PIN 3
#define MC_PIN 8
#define ML_PIN 7
#define BR_PIN 4
#define BC_PIN 10
#define BL_PIN 9

bool state;

void setup() {
  for (int i = 2; i <= 10; ++i) {
    pinMode(i,OUTPUT);
  }
  state = 1;
}

void loop() {
  digitalWrite(TR_PIN, state);
  delay(100);
  digitalWrite(TC_PIN, state);
  delay(100);
  digitalWrite(TL_PIN, state);
  delay(100);
  digitalWrite(ML_PIN, state);
  delay(100);
  digitalWrite(MC_PIN, state);
  delay(100);
  digitalWrite(MR_PIN, state);
  delay(100);
  digitalWrite(BR_PIN, state);
  delay(100);
  digitalWrite(BC_PIN, state);
  delay(100);
  digitalWrite(BL_PIN, state);
  delay(100);

  state = !state;
}
