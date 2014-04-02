#include "jblock.h"
#include <iostream>

using namespace std;

JBlock::JBlock(Board *b) : level(0), type('J'){
	positions = new Coordinate[4];
	config = 1;
	
	positions[0].setX(0);
	positions[0].setY(3);
	positions[1].setX(0);
	positions[1].setY(4);
	positions[2].setX(1);
	positions[2].setY(4);
	positions[3].setX(2);
	positions[3].setY(4);
	
	cout << *b;
}

JBlock::~JBlock(){
	delete [] positions;
}

void JBlock::clockwise(Board *b){ // r and c not needed here
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	if(config == 1){
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

void JBlock::counterclockwise(Board *b){ // r and c not needed here
	return clockwise(b);
}

void JBlock::configOne(int r, int c){
	positions[0] = r-1;
	positions[1] = c;
	positions[2] = r;
	positions[3] = c;
	positions[4] = r;
	positions[5] = c+1;
	positions[6] = r;
	positions[7] = c+2;
}

void JBlock::configTwo(int r, int c){
	positions[0] = r-2;
	positions[1] = c;
	positions[2] = r-1;
	positions[3] = c;
	positions[4] = r;
	positions[5] = c;
	positions[6] = r-2;
	positions[7] = c+1;
}

void JBlock::configThree(int r, int c){
	positions[0] = r-1;
	positions[1] = c;
	positions[2] = r-1;
	positions[3] = c+1;
	positions[4] = r-1;
	positions[5] = c+2;
	positions[6] = r;
	positions[7] = c+2;
}

void JBlock::configFour(int r, int c){
	positions[0] = r;
	positions[1] = c;
	positions[2] = r-2;
	positions[3] = c+1;
	positions[4] = r-1;
	positions[5] = c+1;
	positions[6] = r;
	positions[7] = c+1;
}