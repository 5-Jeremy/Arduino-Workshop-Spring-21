Use these exercises to practice and extend the knowledge you gained during previous workshop sessions. Sample solutions for each of the exercises will be made available after the session following the session in which the exercises were assigned, but it is highly recommended that you try coming to office hours to resolve any difficulties before looking at them.

# Exercise 1: Serial Echo
For your first practice exercise using the serial monitor, lets do something simple: echo any characters recieved by the program back through the serial connection so they show up on the serial monitor. This will be straightforward since you do not need to do any processing of the data recieved.

Hint: There are two ways of doing this for lengthy messages: either read the entire message first and then output it all at once, or read and output each character individually. From my experience, one is much simpler than the other...

Note: for this exercise, you do not need to create a circuit or connect the Arduino board to anything

# Exercise 2: Serial Adder
Assume that your program will be given a series of nonzero integers separated by spaces through the serial port. Write the code to calculate the sum of these integers and print it to the serial monitor. Assume that the entire input will be given at once (when testing, type all of the integers into the input line of the serial monitor before hitting send). Since you cannot input a newline character to the serial monitor in TinkerCAD, use a zero to signify the end of the input.

Hint: The function Serial.parseInt(), which was not discussed in the workshop, will be useful here. You can read the documentation for it [here](https://www.arduino.cc/reference/en/language/functions/communication/serial/parseint/), but the gist is that the function reads bytes from the input buffer and stops after reading the first complete string of consecutive digits, which it interperets as an integer in order to return that integer value.

Note: for this exercise, you do not need to create a circuit or connect the Arduino board to anything
