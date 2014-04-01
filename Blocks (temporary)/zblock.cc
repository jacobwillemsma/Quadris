#include "zblock.h"
#include <iostream>

using namespace std;


int ZBlock::getLevel(){
	return level;
}

void ZBlock::left(){
	// currently does nothing.. should probably be handled by Grid
}

void ZBlock::right(){
	// currently does nothing.. should probably be handled by Grid
}

void ZBlock::down(){
	// currently does nothing.. should probably be handled by Grid
}

void ZBlock::drop(){
	// currently does nothing.. should probably be handled by Grid
}

void ZBlock::clockwise(){
	int temp;
	for(int i = 0; i < 7; i = i + 2){
		temp = positions[i];
		positions[i] = positions[i+1];
		positions[i+1] = temp;
	}
}

void ZBlock::counterclockwise(){
	clockwise();
}

int * ZBlock::getPositions(){
	return positions;
}

ZBlock::ZBlock(int lvl) : level(lvl), type('Z'){
	positions = new int[8];
	
	positions[0] = 0;
	positions[1] = 1;
	positions[2] = 1;
	positions[3] = 1;
	positions[4] = 1;
	positions[5] = 0;
	positions[6] = 2;
	positions[7] = 0;
}

ZBlock::~ZBlock(){
	delete [] positions;
}
