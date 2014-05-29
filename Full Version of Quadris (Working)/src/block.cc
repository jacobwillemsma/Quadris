#include "block.h"
using namespace std;


/*
Constructor and Destructor.
*/

Block::Block() {}
Block::~Block() {}


/*
The following functions are predicate functions that are in charge of making sure that a 
specific move is possible.  There is a specific function for each left, right, down, clockwise
and counterclockwise.  Each function takes in only a Board object.  The general method is to check
if any of the blocks are at a wall or trying to move into a square with a piece.  Each function
returns true if the move is valid and false elsewise.
*/

bool Block::canShiftLeft(Board *b) {
	for (int i = 0; i < 4; i++) {
		if (positions[i].getX() == 0 || b->isOccupied(positions[i].getY(), positions[i].getX() - 1)) 
			return false;
	}
	return true;
}

bool Block::canShiftRight(Board *b) {
	for (int i = 0; i < 4; i++) {
		if (positions[i].getX() == 9 || b->isOccupied(positions[i].getY(), positions[i].getX() + 1)) 
			return false;
	}
	return true;
}

bool Block::canMoveDown(Board *b) {
	for (int i = 0; i < 4; i++) {
		if (positions[i].getY() == 17 || b->isOccupied((positions[i].getY() + 1), positions[i].getX()))
			return false;
	}
	return true;
}


/*
The following functions are void functions that are in charge of actually effectuating a 
specific move.  There is a specific function for each left, right, down, and drop. Clockwise
and counterclockwise are defined in each block as they are different based on block type.  
Each function takes in only a Board object.  The general method is to update the positions
of each coordinate in the area if and on if the corresponding "can" function reigns true.
*/

void Block::left(Board *b) {

	// Clear the display where the block currently is.
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	if (canShiftLeft(b)) {
		// We can shift it.  Effectuate the shift.
		for (int i = 0; i < 4; i++) {
			positions[i].addX(-1);
		}
	}

	// Update the display where ever the block has moved.
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void Block::right(Board *b) {

	// Clear the display where the block currently is.
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}

	if (canShiftRight(b)) {
		// We can shift it.  Effectuate the shift.
		for (int i = 0; i < 4; i++) {
			positions[i].setX(positions[i].getX()+1);
		}
	}

	// Update the display where ever the block has moved.
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}



void Block::down(Board *b) {
	
	// Clear the display where the block currently is.
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
		
	if (canMoveDown(b)) {
		// We can shift it.  Effectuate the shift.
		for (int i = 0; i < 4; i++) {
			positions[i].setY(positions[i].getY() + 1);
		}
	}
	
	// Update the display where ever the block has moved.
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void Block::drop(Board *b) {
	// Clear the display where the block currently is.
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	// As long as we can move down, keep dropping the block.
	while (canMoveDown(b)) {
		for (int i = 0; i < 4; i++) {
			positions[i].setY(positions[i].getY() + 1);
		}
	}
	
	// Update the display where ever the block has moved.
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}


/*
Fetch methods to access protected fields.  Needed for interaction with other objects.
*/

int Block::getLevel() {
	return level;
}

char Block::getType() {
	return type;
}

bool Block::isGameOver(){
	return gameOver;
}