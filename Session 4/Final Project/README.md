# Final Project: Endless Runner Game

![](https://github.com/5-Jeremy/Arduino-Workshop-Spring-21/blob/main/Session%204/Final%20Project/Final%20Project%20Photo.png)

## Goal
You will be creating a very simple example of an endless runner game that can be played on a 16x2 LCD display where the only controls is a single button. You will be focused on writing code that interfaces with the two main devices on the circuit (the button and the LCD) to make the game function. A template is provided for you so that you simply need to implement a set of functions properly to achieve this goal.

## The Circuit
Most of the circuit can be obtained by simply adding the premade Arduino LCD circuit into your TinkerCAD workspace, as discussed in session 4. From there, you simply need to connect a button to one of the open digital pins on the Arduino and make sure you are able to detect whether or not it is pressed.

## The Code
The functions in the template file which you will need to implement are MovePlayer(), MoveObstacles(), SpawnObstacle(), GameSetup(), GameOver(), setup(), and loop(). For detailed information about the purpose of each function, see the comments on the template as well as the session 4 slides and recording.
