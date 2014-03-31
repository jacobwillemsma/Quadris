#include "sblock.h"
#include <iostream>

using namespace std;


int SBlock::getLevel(){
	return level;
}

void SBlock::left(){
	// currently does nothing.. should probably be handled by Grid
}

void SBlock::right(){
	// currently does nothing.. should probably be handled by Grid
}

void SBlock::down(){
	// currently does nothing.. should probably be handled by Grid
}

void SBlock::drop(){
	// currently does nothing.. should probably be handled by Grid
}

void SBlock::clockwise(){
	int temp;
	for(int i = 0; i < 7; i = i + 2){
		temp = positions[i];
		positions[i] = positions[i+1];
		positions[i+1] = temp;
	}
}

void SBlock::counterclockwise(){
	clockwise();
}

SBlock::SBlock(int lvl) : level(lvl), type('S'){
	positions = new int[8];
	
	positions[0] = 0;
	positions[1] = 0;
	positions[2] = 1;
	positions[3] = 1;
	positions[4] = 1;
	positions[5] = 0;
	positions[6] = 2;
	positions[7] = 1;
}

SBlock::~SBlock(){
	delete [] positions;
}
