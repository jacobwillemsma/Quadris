#ifndef __BLOCK_H__
#define __BLOCK_H__
#include "coordinate.h"
#include "board.h"

class Block {
	int level;
	char type;
	Coordinate *positions;

	bool canShiftLeft(Board *b);
	bool canShiftRight(Board *b);
	bool canMoveDown(Board *b);
	bool canRotateClockwise(Board *b);
	bool canRotateCounterClockwise(Board *b);
	
  public:
	virtual ~Block();
	
	void left(Board *b);
	void right(Board *b);
	void down(Board *b);
	void drop(Board *b);
	
	int getLevel();
	char getType();
	
	virtual void clockwise(Board *b) = 0;
	virtual void counterclockwise(Board *b) = 0;
};

#endif