#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "coordinate.h"
#include "board.h"

class Block {
	int level;
	char type;
	Coordinate *positions[4];

	bool canShiftLeft(Board *b);
	bool canShiftRight(Board *b);
	bool canMoveDown(Board *b);
	//canRotateClockwise(Coordinate c, Board *b);
	//canRotateCounterClockwise(Coordinate c, Board *b);
	
  public:
  	Block();
  	void left(Board *b);
  	void right(Board *b);
  	void down(Board *b);
  	void drop(Board *b);
};

#endif