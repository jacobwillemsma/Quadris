#include "block.h"
using namespace std;

Block::Block() {}
Block::~Block(){
	delete [] positions;
}

// ALL OF THE "CAN" FUNCTIONS NEED TO BE FIXED.

bool Block::canShiftLeft(Board *b) {
	for (int i = 0; i < 4; i++) {
		if (positions[i].getX() == 0 || b->isOccupied(positions[i].getY(), positions[i].getX() - 1)) 
			return false;
	}
	return true;
}

bool Block::canShiftRight(Board *b) {
	Coordinate *temp = new Coordinate[4];
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

bool Block::canRotateClockwise(Board *b) {
	return true;
}

bool Block::canRotateCounterClockwise(Board *b) {
	return true;
}

void Block::left(Board *b) {
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	if (canShiftLeft(b)) {
		// We can shift it left.  Effectuate the shift and print update the display.
		for (int i = 0; i < 4; i++) {
			positions[i].addX(-1);
		}
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void Block::right(Board *b) {
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	if (canShiftRight(b)) {
		// We can shift it left.  Effectuate the shift and print update the display.
		for (int i = 0; i < 4; i++) {
			positions[i].setX(positions[i].getX()+1);
		}
	}
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}



void Block::down(Board *b) {
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
		
	if (canMoveDown(b)) {
		for (int i = 0; i < 4; i++) {
			positions[i].setY(positions[i].getY() + 1);
		}
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void Block::drop(Board *b) {
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	while (canMoveDown(b)) {
		for (int i = 0; i < 4; i++) {
			positions[i].setY(positions[i].getY() + 1);
		}
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

int Block::getLevel() {
	return level;
}

char Block::getType() {
	return type;
}

bool Block::isGameOver(){
	return gameOver;
}