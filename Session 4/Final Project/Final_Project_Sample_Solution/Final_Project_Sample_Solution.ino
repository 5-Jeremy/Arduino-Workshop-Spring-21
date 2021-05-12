/*
 * Code author: Jeremy Carleton
 * This code shows an example of how each of the final project functions could be implemented.
 * It follows the explanations provided during the introduction to the final project in session
 * 4 pretty closely, so you should watch session 4 in order to most easily understand this code
 * if you have not already.
 */

/****** Libraries used ******/
#include <LiquidCrystal.h>
/****** Game parameters ******/
#define move_delay 100 // Determines the period between updates to obstacle position
#define spawn_delay 500 // Determines the period between new obstacles appearing
#define player_char '@'
#define obstacle_char '['
#define max_obstacles 3

// initialize the library with the numbers of the interface pins
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
  static int last_state = BTN_UP;
  switch(digitalRead(7)) {
    case 0:
      if (last_state == BTN_UP) { // Button pressed
        lcd.setCursor(player.col, player.row);
        lcd.write(' ');
        player.row = !player.row;
        lcd.setCursor(player.col, player.row);
      lcd.write(player.image);
      }
      last_state = BTN_DOWN;
      break;
    default:
      last_state = BTN_UP;
      break;
  }
}

// currObstacles keeps track of the number of obstacles onscreen
int currObstacles;
// One array for each row on the display is used to keep track of obstacles
entity* row0Entities[16];
entity* row1Entities[16];

// Use this function to move all of the obstacles towards the player by one space
  // All movement can be accomplished using the SetObstaclePosition function
  // Don't forget to check for a collision with the player, and make sure you cover both arrays
void MoveObstacles() {
  for (int i = 0; i < 16; ++i) {
    
    // Don't try to move an obstacle from a space where none exists
      // The SetObstaclePosition function will check for this, but there is no point in calling it if we know
      // there is no obstacle here
    if (row0Entities[i] != NULL) {
      // Handle the case where the obstacle has reached the left side
      if (i == player.col && player.row == 0) {
        // If both the player and the obstacle are on the same space then its game over
        GameOver();
      }
      else {
        SetObstaclePosition(0, i, 0, i-1); // Move obstacle one space
      }
    }
    // Repeat for row1Entities
    if (row1Entities[i] != NULL) {
      // Handle the case where the obstacle has reached the left side
      if (i == player.col && player.row == 1) {
        // If both the player and the obstacle are on the same space then its game over
        GameOver();
      }
      else {
        SetObstaclePosition(1, i, 1, i-1); // Move obstacle one space
      }
    }
    
  }
}

void SpawnObstacle() {
  if (currObstacles >= max_obstacles) return;
  bool row = (bool)random(2);
  if (AddObstacle(row, 15)) {
    return;
  }
  else {
    AddObstacle(!row, 15);
  }
}

int numGames;
int gameTime;
// spawnTimer keeps track of the millisecond passed since an obstacle was spawned
int spawnTimer;
// movementTimer keeps track of the millisecond passed since the obstacles last moved
int movementTimer;
void GameSetup() {
  ++numGames;
  player.row = 0;
  // Need to add player to screen once at the start of the game
  lcd.setCursor(player.col, player.row);
  lcd.write(player.image);
  // Clear the internal arrays
  ClearObstacleArrays();
  // Use previous game's runtime to (hopefully) get a new seed each time
  randomSeed(gameTime);
  // Reset counters
  movementTimer = 0;
  spawnTimer = 0;
  currObstacles = 0;
  gameTime = 0;
}

void GameOver() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Game Over");
  delay(1000);
  lcd.clear();
  // Output score, which is the number of full seconds survived
  Serial.print("Game ");
  Serial.print(numGames);
  Serial.print(": ");
  Serial.println(gameTime/1000);
  // Reset the game
  GameSetup();
}
  

void setup() {
  // Using serial monitor to print out scores
  Serial.begin(9600);
  pinMode(7,INPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Initialize player data; starting location is top left
  // (note: row 1 is the second row, since counting begins with 0):
  player.row = 0;
  player.col = 0;
  player.image = player_char;
  // Set up the game
  gameTime = 0;
  numGames = 0;
  GameSetup();
}

void loop() {
  MovePlayer();
  if (movementTimer >= move_delay) {
    MoveObstacles();
    movementTimer = 0;
  }
  if (spawnTimer >= spawn_delay) {
    SpawnObstacle();
    spawnTimer = 0;
  }
  delay(1);
  movementTimer++;
  spawnTimer++;
  gameTime++;
}

/******** Helper function definitions ********/
// NOTE: You do not need to change any of these functions in order to achieve the essential functionality
  // if the endless runner minigame. Simply call these functions to perform the actions described in the comments
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
