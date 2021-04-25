# Custom Lightshow Project

## Goal
You are being given the schematic for a pre-made circuit which interfaces 9 light emitting diodes (LEDs) with an Arduino board to allow independent control of each LED. Your goal is to write code which flashes the LEDs in a sequence that you define, and then re-create the circuit on TinkerCAD such that you can verify the correctness of your program.

## The Circuit

### Update 4/24/21: An example of the circuit reproduced in TinkerCAD can be found at this link: https://www.tinkercad.com/things/5SjstsTi532.

The circuit consists of a 3x3 grid of LEDs, each of which is grounded (via one of the GND pins of the Arduino) on the cathode side and connected to a digital pin of the Arduino on the anode side (with a 330 ohm resistor in between to limit current). A full schematic is provided below.
![](https://github.com/5-Jeremy/Arduino-Workshop-Spring-21/blob/development/Session%202/Lightshow%20Project/Lightshow%20Circuit%20Schematic.png)
Note that the three rows of LEDs have been labeled ‘top’, ‘middle’, and ‘bottom’, while the three columns have been labeled ‘left’, ‘center’, and ‘right’. This will come in handy when keeping track of which pin corresponds to which LED. For reference, the pin number which controls each LED in the grid is shown in the following table.
|        | Left   | Center | Right |
| ---:   | :----: | :----: | :---: | 
|   Top  | 5      | 6      | 2     |
| Middle | 7      | 8      | 3     |
| Bottom | 9      | 10     | 4     |

## The Program
You are being given the freedom to implement the program for your lightshow however you want, however it is recommended that you keep the duration of a full cycle of the lightshow under 20 seconds. For tips on how to write your program, watch the recording for session 2 of this workshop series.
