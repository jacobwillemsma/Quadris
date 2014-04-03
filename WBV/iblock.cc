#include "iblock.h"
#include <iostream>

using namespace std;

IBlock::IBlock(Board *b) {
	level = 0;
	type = 'I';
	positions = new Coordinate[4];
	for (int i = 0; i < 4; i++) {
		positions[i].setX(i);
		positions[i].setY(3);
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
	cout << *b;
}

IBlock::~IBlock(){
	delete [] positions;
}

void IBlock::clockwise(Board *b){ // r and c not needed here
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

void IBlock::counterclockwise(Board *b){ // r and c not needed here
	return clockwise(b);
}