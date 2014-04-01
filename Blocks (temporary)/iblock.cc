#include "iblock.h"
#include <iostream>

using namespace std;


int IBlock::getLevel(){
	return level;
}

void IBlock::left(){
	// currently does nothing.. should probably be handled by Grid
}

void IBlock::right(){
	// currently does nothing.. should probably be handled by Grid
}

void IBlock::down(){
	// currently does nothing.. should probably be handled by Grid
}

void IBlock::drop(){
	// currently does nothing.. should probably be handled by Grid
}

void IBlock::clockwise(){
	int temp;
	for(int i = 0; i < 7; i = i + 2){
		temp = positions[i];
		positions[i] = positions[i+1];
		positions[i+1] = temp;
	}
}

void IBlock::counterclockwise(){
	clockwise();
}

int * IBlock::getPositions(){
	return positions;
}

IBlock::IBlock(int lvl) : level(lvl), type('I'){
	positions = new int[8];
	
	positions[0] = 0;
	positions[1] = 0;
	positions[2] = 1;
	positions[3] = 0;
	positions[4] = 2;
	positions[5] = 0;
	positions[6] = 3;
	positions[7] = 0;
}

IBlock::~IBlock(){
	delete [] positions;
}
