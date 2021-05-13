/*
 * Code author: Jeremy Carleton
 * Use this code as a template to start out your final project, and add code to the incomplete functions
 * in order to complete the project. For further guidance, see the session 4 slides or recording.
 * 
 * Watch session 4 here:
 * https://www.youtube.com/watch?v=7CSGJm4wRhA&list=PLfmzHX29KVv_cbdHYJD3cuvoo_Valq8us&index=5
 */

/****** Libraries used ******/
#include <LiquidCrystal.h>
/****** Game parameters ******/
#define move_delay 100 // Determines the period between updates to obstacle position
#define spawn_delay 500 // Determines the period between new obstacles appearing
#define player_char '@' // Sets the appearance of the player character on the screen
#define obstacle_char '[' // Sets the appearance of the obstacles on the screen
#define max_obstacles 3 // Determines the maximum number of obstacles that will appear at once

// initialize the library with the numbers of the interface pins
  // The pins used here match the pins used in the pre-made TinkerCAD circuit
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/****** Struct for storing information about game objects ******/
typedef struct _entity {
  bool row; // The row number can either be 0 or 1, corresponding to the top and bottom rows on the display
  int col;  // The column number can be any integer from 0 to 15
  char image; // The image drawn on the display to represent this object
} entity;

/******** Helper functions ********/
// The implementation of these helper functions is found at the end of this file, but you do not need
  // to look at them for now

// Changes an obstacle's position on the display and updates its position in the internal arrays
  // If the obstacle would go off of the display screen (ie. column is less than 0), it is removed from memory instead,
  // allowing a new obstacle to spawn (since the obstacle count is automatically updated)
  // To use, pass in the row and column on the display where the obstacle is currently located for oldRow and oldCol,
  // and pass in the desired new row and column for newRow and newCol
void SetObstaclePosition(bool oldRow, int oldCol, bool newRow, int newCol);
// Adds an obstacle in the position specified by arguments row and col
  // Also returns true if the position was open for the new spawn, or false if the spawn failed because the position
  // was blocked or invalid. Note that the obstacle count is automatically updated
bool AddObstacle(bool row, int col);
// Removes all obstacles from the internal arrays; used to reset the game
void ClearObstacleArrays();

entity player; // The player is defined globally because it needs to persist throughout the program

enum BTN_STATE {BTN_UP, BTN_DOWN};
// Player entity changes rows when button is pressed, and cannot change columns
  // Use the enum above to set up a state machine that redraws the player on the opposite row
  // when the button is pressed
void MovePlayer() {

}

// currObstacles keeps track of the number of obstacles onscreen
int currObstacles;
// One array for each row on the display is used to keep track of obstacles
entity* row0Entities[16];
entity* row1Entities[16];

// Use this function to move all of the obstacles towards the player by one space
  // All movement can be accomplished using the SetObstaclePosition function
  // You will need to check for a collision with the player and trigger a game over if a collision happens
  // Make sure you cover both arrays
void MoveObstacles() {
  for (int i = 0; i < 16; ++i) {

  }
}

// When adding an obstacle, first determine the row to add it to by generating a random value of
  // either 0 or 1, then use the AddObstacle() helper function
  // Make sure you do not spawn an obstacle if the maximum number of obstacles already exists
void SpawnObstacle() {

}

// numGames keeps track of the number of games played so far for the purposes of the scoreboard
int numGames;
// gameTime keeps track of the overall number of milliseconds passed since the start of a game
  // for calculating the score
int gameTime;
// spawnTimer keeps track of the milliseconds passed since an obstacle was spawned
int spawnTimer;
// movementTimer keeps track of the milliseconds passed since the obstacles last moved
int movementTimer;
// Unlike the standard setup() function, this function should be called each time a new game starts
  // The actions that this function must perform are to update the variables listed above, add the
  // player to the screen in the top left corner, remove all obstacles (the helper function
  // ClearObstacleArrays() will help with this), and set a new random seed based on the length of
  // the previous game, which is sufficiently random for this purpose
void GameSetup() {

}

// This function should be called when an obstacle collides with the player. 
  // It should clear the lcd screen, display the text "Game Over" for 1 second,
  // and print the game number and the player's score in this format:
  // Game <number>: <score>
  // where the score is the number of full seconds for which the game lasted 
  // (note that gameTime is in milliseconds, and will need to be converted).
  // At the end of this function, GameSetup() should be called to prepare for the
  // next game
void GameOver() {

}
  
// This function performs all of the same actions as GameSetup() (which
  // can be accomplished by simply calling that function at the end), and
  // also initializes the Serial and lcd objects, sets the pin mode of 
  // the pin connected to the button, sets the initial random seed (you 
  // can just use a constant number here), initializes the position and
  // image for the player entity, and sets numGames to zero
void setup() {

}

// This function just calls other functions and updates counters as needed while 
  // the game is running. MovePlayer() should be called on each execution, but 
  // the functions MoveObstacles() and SpawnObstacle() only need to be called
  // when their respective timers movementTimer and spawnTimer reach the values
  // of move_delay and spawn_delay defined at the top of the code, at which point
  // the respective function is called and the timer is reset to zero. There
  // should be a delay of 1 millisecond before incrementing the timers each time
  // this function executes so that each timer will measure the approximate time
  // elapsed in milliseconds
void loop() {

}

/******** Helper function definitions ********/
// NOTE: You do not need to change any of these functions in order to achieve the essential functionality
  // of the endless runner minigame. Simply call these functions to perform the actions described in the comments
  // at the top of this file

void SetObstaclePosition(bool oldRow, int oldCol, bool newRow, int newCol) {
  // Temporary pointer
  entity* e;
  // Clear the obstacle from its old location
  lcd.setCursor(oldCol, oldRow);
  lcd.write(' ');
  // Create a pointer to the entity that needs to be moved
  if (oldRow == 0){
    // Don't try to move an obstacle from a space where none exists
    if (row0Entities[oldCol] == NULL) {
      return;
    }
    else {
      e = row0Entities[oldCol]; // Store in temporary pointer
      row0Entities[oldCol] = NULL; // Don't need this pointer set anymore
    }
  }
  else {
    if (row1Entities[oldCol] == NULL) {
      return;
    }
    else {
      e = row1Entities[oldCol];
      row1Entities[oldCol] = NULL;
    }
  }
  // Obstacle is no longer on screen, remove it
  if (newCol < 0 || newCol > 15) {
    --currObstacles;
    free(e);
    return;
  }
  // Update position data stored in the entity struct
  e->row = newRow;
  e->col = newCol;
  // Redraw in new position
  lcd.setCursor(newCol,newRow);
  lcd.write(e->image);
  // Assign the pointer in the correct position in the array to the temporary pointer before it goes out of scope
  if (newRow == 0){
    row0Entities[newCol] = e;
  }
  else {
    row1Entities[newCol] = e;
  }   
}

bool AddObstacle(bool row, int col) {
  // Cannot spawn an obstacle outside of the screen (need to prevent out-of-bounds array indexing)
  if (col < 0 || col > 15) return false;
  if (row == 0) {
    if (row0Entities[col] != NULL) {
      return false;
    }
  }
  else {
    if (row1Entities[col] != NULL) {
      return false;
    }
  }
  // Create the entity to spawn, stored in a temporary pointer
  entity* e = (entity*)malloc(sizeof(entity));
  if (e == NULL) return false;
  e->col = col;
  e->row = 0;
  e->image = obstacle_char;
  ++currObstacles;
  if (row == 0) {
    row0Entities[col] = e;
  }
  else {
    row1Entities[col] = e;
  }
  return true;
}

void ClearObstacleArrays() {
  for (int i = 0; i < 16; ++i) {
    // lists start empty, and are populated as the game goes on
    if (row0Entities[i] != NULL) free(row0Entities[i]);
    row0Entities[i] = NULL;
    if (row1Entities[i] != NULL) free(row1Entities[i]);
    row1Entities[i] = NULL;
  }
}
