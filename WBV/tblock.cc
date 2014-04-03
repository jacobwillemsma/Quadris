#include "tblock.h"
#include <iostream>

using namespace std;

TBlock::TBlock(Board *b) {
	level = 0;
	type = 'T';
	positions = new Coordinate[4];
	config = 1;
	
	positions[0].setX(0);
	positions[0].setY(3);
	positions[1].setX(1);
	positions[1].setY(3);
	positions[2].setX(1);
	positions[2].setY(4);
	positions[3].setX(2);
	positions[3].setY(3);

	// Let the cells and the display know that they are present.
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

TBlock::~TBlock() {
	delete [] positions;
}

void TBlock::clockwise(Board *b){ // r and c not needed here
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	if(config == 1){
		configTwo(positions[0].getY()+1, positions[0].getX());
	}
	else if(config == 2){
		configThree(positions[0].getY()+1, positions[0].getX());
	}
	else if(config == 3){
		configFour(positions[0].getY(), positions[0].getX());
	}
	else if(config == 4){
		configOne(positions[2].getY(), positions[2].getX());
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void TBlock::counterclockwise(Board *b){ // r and c not needed here
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	if(config == 1){
		configFour(positions[0].getY()+1, positions[0].getX());
	}
	else if(config == 2){
		configOne(positions[0].getY()+1, positions[0].getX());
	}
	else if(config == 3){
		configTwo(positions[0].getY(), positions[0].getX());
	}
	else if(config == 4){
		configThree(positions[2].getY(), positions[2].getX());
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void TBlock::configOne(int r, int c){
	positions[0].setY(r-1);
	positions[0].setX(c);
	positions[1].setY(r-1);
	positions[1].setX(c+1);
	positions[2].setY(r);
	positions[2].setX(c+1);
	positions[3].setY(r-1);
	positions[3].setX(c+2);
}

void TBlock::configTwo(int r, int c){
	positions[0].setY(r-1);
	positions[0].setX(c);
	positions[1].setY(r-2);
	positions[1].setX(c+1);
	positions[2].setY(r-1);
	positions[2].setX(c+1);
	positions[3].setY(r);
	positions[3].setX(c+1);
}

void TBlock::configThree(int r, int c){
	positions[0].setY(r);
	positions[0].setX(c);
	positions[1].setY(r-1);
	positions[1].setX(c+1);
	positions[2].setY(r);
	positions[2].setX(c+1);
	positions[3].setY(r);
	positions[3].setX(c+2);
}

void TBlock::configFour(int r, int c){
	positions[0].setY(r-2);
	positions[0].setX(c);
	positions[1].setY(r-1);
	positions[1].setX(c);
	positions[2].setY(r);
	positions[2].setX(c);
	positions[3].setY(r-1);
	positions[3].setX(c+1);
}