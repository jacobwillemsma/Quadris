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
		configTwo(positions[1].getY(), positions[1].getX());
	}
	else if(config == 2){
		configThree(positions[2].getY(), positions[2].getX());
	}
	else if(config == 3){
		configFour(positions[0].getY() + 1, positions[0].getX());
	}
	else if(config == 4){
		configOne(positions[0].getY(), positions[0].getX());
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void JBlock::counterclockwise(Board *b){ // r and c not needed here
	if(config == 1){
		configFour(positions[0].getY() + 1, positions[0].getX());
	}
	else if(config == 2){
		configOne(positions[0].getY(), positions[0].getX());
	}
	else if(config == 3){
		configTwo(positions[1].getY(), positions[1].getX());
	}
	else if(config == 4){
		configThree(positions[2].getY(), positions[2].getX());
	}
}

void JBlock::configOne(int r, int c){
	positions[0].setY(r-1);
	positions[0].setX(c);
	positions[1].setY(r);
	positions[1].setX(c+1);
	positions[2].setY(r);
	positions[2].setX(c+1);
	positions[3].setY(r);
	positions[3].setX(c+2);
}

void JBlock::configTwo(int r, int c){
	positions[0].setY(r-2);
	positions[0].setX(c);
	positions[1].setY(r-1);
	positions[1].setX(c);
	positions[2].setY(r);
	positions[2].setX(c);
	positions[3].setY(r-2);
	positions[3].setX(c+1);
}

void JBlock::configThree(int r, int c){
	positions[0].setY(r-1);
	positions[0].setX(c);
	positions[1].setY(r-1);
	positions[1].setX(c+1);
	positions[2].setY(r-1);
	positions[2].setX(c+2);
	positions[3].setY(r);
	positions[3].setX(c+2);
}

void JBlock::configFour(int r, int c){
	positions[0].setY(r);
	positions[0].setX(c);
	positions[1].setY(r-2);
	positions[1].setX(c+1);
	positions[2].setY(r-1);
	positions[2].setX(c+1);
	positions[3].setY(r);
	positions[3].setX(c+1);
}