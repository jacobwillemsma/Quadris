#include "block.h"
#include <iostream>
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
		if (positions[i].getX() == 0 /*|| b->isOccupied(positions[i].getX(), positions[i].getY())*/) 
			return false;
	}
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
	}
}

bool Block::canShiftRight(Board *b) {
	for (int i = 0; i < 4; i++) {
		if (positions[i].getX() == 9 /*|| b->isOccupied(positions[i].getX(), positions[i].getY())*/)
			return false;
	}
	return true;
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
	}
}

bool Block::canMoveDown(Board *b) {
	for (int i = 0; i < 4; i++) {
		if (positions[i].getY() == 17 /*|| b->isOccupied(positions[i].getX(), positions[i].getY())*/)
			return false;
	}
	return true;
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
	}
}

void Block::drop(Board *b) {
	while (canMoveDown(b)) {
		down(b);
	}
}

void Block::clockwise(Board *b){ // r and c not needed here
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	if(positions[0].getY() == positions[1].getY()){
		positions[0].addY(-3);
		// positions[0].addX() does not change
		positions[1].addY(-2);
		positions[1].addX(-1);
		positions[2].addY(-1);
		positions[2].addX(-2);
		// positions[3] does not change
		positions[3].addX(-3);
	}
	else if(positions[0].getX() == positions[1].getX()){
		if(positions[0].getX() < 7){
			positions[0].addY(3);
			// positions[0].addY() does not change
			positions[1].addY(2);
			positions[1].addX(1);
			positions[2].addY(1);
			positions[2].addX(2);
			// positions[3].addY() does not change
			positions[3].addX(3);
		}
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void Block::counterclockwise(Board *b){ // r and c not needed here
	return clockwise(b);
}

int Block::getLevel(){
	return level;
}

char Block::getType(){
	return type;
}