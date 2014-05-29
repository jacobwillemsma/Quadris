#include "oblock.h"
using namespace std;

/*
Constructor and destructor.
The constructor is in charge of creating the initial positions of a block
on the board.
The destructor deletes the position area or coordinates.
*/

OBlock::OBlock(Board *b, int lvl) {
	level = lvl;
	type = 'O';
	positions = new Coordinate[4];
	
	positions[0].setX(0);
	positions[0].setY(3);
	positions[1].setX(0);
	positions[1].setY(4);
	positions[2].setX(1);
	positions[2].setY(3);
	positions[3].setX(1);
	positions[3].setY(4);
	
	gameOver = false;
	for (int i = 0; i < 4; i++) {
		if (b->isOccupied(positions[i].getY(), positions[i].getX()))
			gameOver = true;
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

OBlock::~OBlock(){
	delete [] positions;
}


/*
OBlocks cannot rotate.
*/

void OBlock::clockwise(Board *b){}

void OBlock::counterclockwise(Board *b){}