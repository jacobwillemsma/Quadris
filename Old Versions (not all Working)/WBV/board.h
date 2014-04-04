#ifndef __BOARD_H__
#define __BOARD_H__
#include "cell.h"
#include "coordinate.h"

class Board {
	// constants for the size of the board
	int BOARD_HEIGHT;
	int BOARD_WIDTH;
	
	Coordinate *current;
	
	Cell **theBoard; // contains the cells that make up the game board	
	TextDisplay *td; // textDisplay for the game

  public:
	Board();
	void setCurrent(Coordinate *curr, char type);
	void update(int r, int c, char type);
	bool isOccupied(int r, int c); // checks if a Cell is occupied
	friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif