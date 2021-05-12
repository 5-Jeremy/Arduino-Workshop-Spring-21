/*
 * Code author: Jeremy Carleton
 * This code was used in the demo showing how to
 * use a state machine to control a lightshow
 * 
 * To see the code being demonstrated, watch
 * session 2 of the workshop series here:
 * https://www.youtube.com/watch?v=hzs0jgZLPTU&list=PLfmzHX29KVv_cbdHYJD3cuvoo_Valq8us&index=3
 */

enum States {off, odd, even} state;
bool next_state; // 0 means odd, 1 means even
int SM_time; // counts time in seconds, since the duration
		          // for each state is a multiple of 1 second

// Map LED number to pin number
// LED 0 uses pin 5, LED 1 uses pin 4, etc
int GetPinFromNum(int LED_num) {
  return 5 - LED_num;
}

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  state = off; // set initial state
  next_state = 0; // first lights to flash will be odd
  SM_time = 0;
}


void loop()
{
  
  // Switch statements are used in most state machines
  // to control the code that is executed based on the
  // current state
  switch(state) {
    // A case is a possible value of state
    case off:
      for (int i=0; i<4; ++i) { digitalWrite(GetPinFromNum(i),0); }
      // Note the fancy syntax used to conditionally assign
      // state with one of two values
      if (SM_time >= 1) { 
        state = next_state ? even : odd; 
        SM_time = 0;
      }
    // Use break to indicate the end of a case
    break;
    case odd:
      digitalWrite(GetPinFromNum(1),1);
      digitalWrite(GetPinFromNum(3),1);
      if (SM_time >= 2) { 
        state = off; 
        SM_time = 0;
        next_state = 1;
      }
    break;
    case even:
      digitalWrite(GetPinFromNum(0),1);
      digitalWrite(GetPinFromNum(2),1);
      if (SM_time >= 2) { 
        state = off; 
        SM_time = 0;
        next_state = 0;
      }
    break;
    // The default case should never execute here
    // If it does, there is a bug
    default: break;
    
  }
  // After performing the actions required for the current state,
  // advance the time and repeat
  SM_time++;
  delay(1000);
}
