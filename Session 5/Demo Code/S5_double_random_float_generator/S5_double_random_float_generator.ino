/*
 * Code author: Jeremy Carleton
 * This code was used during the demonstration in session 5 to send a pair of float values
 * that can be received in Simulink and logged to the MATLAB workspace. In order to replicate
 * this yourself, you need to install the software explained in the README for session 5 and 
 * then follow the directions from session 5 to setup the Simulink model.
 * 
 * Watch session 5 of the workshop series here: 
 * https://www.youtube.com/watch?v=_glpVfHw2qg&list=PLfmzHX29KVv_cbdHYJD3cuvoo_Valq8us&index=6
 */

typedef union{
  float val;
  uint8_t bytes[4];
} float_union;

float_union data1;
float_union data2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Introduce a delay to simulate the sampling rate of a sensor
  delay(50);
  // Send the header character before each set of data to allow the serial recieve block to
    // identify data points from different samples
  Serial.write('G'); 
  // Generate two random data point between 0 and 1, and store them in their respective
    // unions as float values
  data1.val = random(0,100)/100.0;
  data2.val = random(0,100)/100.0;
  // For each data point, send the data in the union as a set of 4 bytes, which will be 
    // interpereted as a single by the Simulink model
  for (int i=0; i<4; i++){
    Serial.write(data1.bytes[i]); 
  }
  for (int i=0; i<4; i++){
    Serial.write(data2.bytes[i]); 
  }
  // Send the terminator character after each set of data
  Serial.print('\n');
}
