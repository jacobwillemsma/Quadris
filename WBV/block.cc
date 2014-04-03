#include "block.h"
using namespace std;

Block::Block() {}
Block::~Block(){
	delete [] positions;
	delete [] rightPositions;
	delete [] leftPositions;
	delete [] downPositions;
}

// ALL OF THE "CAN" FUNCTIONS NEED TO BE FIXED.

bool Block::canShiftLeft(Board *b) {
	for (int i = 0; i < leftNum; i++) {
		if (leftPositions[i].getX() == 0 || b->isOccupied(leftPositions[i].getY(), (leftPositions[i].getX() - 1))) 
			return false;
	}
	return true;
}

bool Block::canShiftRight(Board *b) {

	for (int i = 0; i < rightNum; i++) {
		//cout << "Checking location (" << rightPositions[i].getY() + 1 << "," << rightPositions[i].getX() << ") and it is " << b->isOccupied((rightPositions[i].getY() + 1), rightPositions[i].getX()) << " occupied." << endl;
		if (rightPositions[i].getX() == 9 || b->isOccupied(rightPositions[i].getY(), (rightPositions[i].getX() + 1))) 
			return false;
	}
	return true;
}

bool Block::canMoveDown(Board *b) {
	for (int i = 0; i < downNum; i++) {
		//cout << "Checking location (" << downPositions[i].getY() + 1 << "," << downPositions[i].getX() << ") and it is " << b->isOccupied((downPositions[i].getY() + 1), downPositions[i].getX()) << " occupied." << endl;
		if (downPositions[i].getY() == 17 || b->isOccupied((downPositions[i].getY() + 1), downPositions[i].getX()))
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
	if (canShiftLeft(b)) {
		// Update the display
		for (int i = 0; i < 4; i++) {
			b->update(positions[i].getY(), positions[i].getX(), ' ');
		}
		// We can shift it left.  Effectuate the shift and print update the display.
		for (int i = 0; i < 4; i++) {
			positions[i].addX(-1);
		}
		// Update the display
		for (int i = 0; i < 4; i++) {
			b->update(positions[i].getY(), positions[i].getX(), type);
		}
		updatePositions();
	}
}

void Block::right(Board *b) {
	if (canShiftRight(b)) {
		// Update the display
		for (int i = 0; i < 4; i++) {
			b->update(positions[i].getY(), positions[i].getX(), ' ');
		}
		// We can shift it left.  Effectuate the shift and print update the display.
		for (int i = 0; i < 4; i++) {
			positions[i].setX(positions[i].getX()+1);
		}
		// Update the display
		for (int i = 0; i < 4; i++) {
			b->update(positions[i].getY(), positions[i].getX(), type);
		}
		updatePositions();
	}
}



void Block::down(Board *b) {
	if (canMoveDown(b)) {
		// Update the display
		for (int i = 0; i < 4; i++) {
			b->update(positions[i].getY(), positions[i].getX(), ' ');
		}
		for (int i = 0; i < 4; i++) {
			positions[i].setY(positions[i].getY() + 1);
		}
		// Update the display
		for (int i = 0; i < 4; i++) {
			b->update(positions[i].getY(), positions[i].getX(), type);
		}
		updatePositions();
	}
}

void Block::drop(Board *b) {
	while (canMoveDown(b)) {
		down(b);
		updatePositions();
	}
}

int Block::getLevel() {
	return level;
}

char Block::getType() {
	return type;
}