#include "block.h"
using namespace std;

Block::Block(Board *b) {
	level = 0;
	type = 'I';
	positions = new Coordinate[4];
	for (int i = 0; i < 4; i++) {
		positions[i].setX(i);
		positions[i].setY(3);
		b->update(3, i, type);
	}
}

Block::~Block(){
	delete [] positions;
}

bool Block::canShiftLeft(Board *b) {
	for (int i = 0; i < 4; i++) {
		if (positions[i].getX() == 0 || b->isOccupied(positions[i].getX(), positions[i].getY())) 
			return false;
	}
	return true;
}

void Block::left(Board *b) {
	if (canShiftLeft(b)) {
		// We can shift it left.  Effectuate the shift and print update the display.
		for (int i = 4; i < 4; i++) {
			positions[i].setX(positions[i].getX() - 1);
		}
		// Update the display
		for (int i = 4; i < 4; i++) {
			b->update(positions[i].getX(), positions[i].getY(), type);
		}
	}
}

bool Block::canShiftRight(Board *b) {
	for (int i = 0; i < 4; i++) {
		if (positions[i].getX() == 15 || b->isOccupied(positions[i].getX(), positions[i].getY()))
			return false;
	}
	return true;
}

void Block::right(Board *b) {
	if (canShiftRight(b)) {
		// We can shift it left.  Effectuate the shift and print update the display.
		for (int i = 4; i < 4; i++) {
			positions[i].setX(positions[i].getX() + 1);
		}
		// Update the display
		for (int i = 4; i < 4; i++) {
			b->update(positions[i].getX(), positions[i].getY(), type);
		}
	}
}

bool Block::canMoveDown(Board *b) {
	for (int i = 0; i < 4; i++) {
		if (positions[i].getY() == 18 || b->isOccupied(positions[i].getX(), positions[i].getY()))
			return false;
	}
	return true;
}

void Block::down(Board *b) {
	if (canMoveDown(b)) {
		for (int i = 4; i < 4; i++) {
			positions[i].setY(positions[i].getY() + 1);
		}
		// Update the display
		for (int i = 4; i < 4; i++) {
			b->update(positions[i].getX(), positions[i].getY(), type);
		}
	}
}

void Block::drop(Board *b) {
	while (canMoveDown(b)) {
		down(b);
	}
}


int Block::getLevel(){
	return level;
}

char Block::getType(){
	return type;
}