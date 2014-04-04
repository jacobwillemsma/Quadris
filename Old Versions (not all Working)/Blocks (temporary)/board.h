#ifndef __BOARD_H__
#define __BOARD_H__

#include "nextblock.h"
#include "cell.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "tblock.h"
#include "oblock.h"
#include "zblock.h"
#include "sblock.h"
#include "display.h"
//#include "xwindow.h"

#include <iostream>
#include <string>

class Board {
	// constants for the size of the board
	const int BOARD_HEIGHT = 15;
	const int BOARD_WIDTH = 10;
	const int BLOCK_SIZE = 4;
	// this may be covered by the nextBlock class
	// const int FILE_NAME = "sequence.txt"
	
	Cell **theBoard; // contains the cells that make up the game board
	Block current; // holds the current (moving) game block
	Block next; // holds the next, or upcoming, block
	
	int * currentPosition[BLOCK_SIZE*2]; // hold the current Block position (not changed until a Block move is cleared)
	int * nextPosition[BLOCK_SIZE*2]; // holds the next move, or potential move for the current Block
	int level; // marks the level
	
	//std::string source; may be covered by nextBlock
	
	TextDisplay *td; // textDisplay for the game
	//XWindow *xw;
	
	void clearBoard(); // clears the board
	void clearRow(int r); // 'deletes' a row, ie sets all Cells to ' '
	void gameStart(); // starts a game
	void rowsChecker(); // checks if ANY row have been completed
	bool rowFull(int r); // checks if a single row is full and returns true if it is
	void removeRow(int r); // removes a row, and all above 'fall down'
	bool isOccupied(int r, int c); // checks if a Cell is occupied
	
	void revert(int move); // reverts the current Block's coordinates to the previous coordinates if move not viable
	
	bool gameOver(); // will return true if the next Block is not able to enter the board
	
	Block getBlock(string b); // returns a block
	Block getRandBlock(); // returns a 'random' block
	
	void updateDisplay(); // updates the display
	
  public:
	Board();
	~Board();
	
	// calls down, left, right, clockwise or counterclockwise on the current block
	bool down();
	bool left();
	bool right();
	bool clockwise();
	bool counterclockwise();
	
	// drops the current block and makes the next block the current block, as well as generating a new current block
	bool drop();
	
	// changes the game level up or down
	void levelUp();
	void levelDown();
	
	
	Cell getCell(int r, int c); // gets the Cell at location r, c
	// bool canPlay();  removing
	
	void restartGame(); // restarts the game by clearing the board and creating a new current, next, score to zero, etc.
	
	friend std::ostream &operator<<(std::ostream &out, Grid g); // prints the Grid
};

#endif