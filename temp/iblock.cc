#include "iblock.h"
#include <iostream>

using namespace std;


bool IBlock::clockwise(int r, int c){ // r and c not needed here
	if(positions[0] == positions[2]){
		positions[0] -= 3;
		// positions[1] does not change
		positions[2] -= 2;
		positions[3] -= 1;
		positions[4] -= 1;
		positions[5] -= 2;
		// positions[6] does not change
		positions[7] -= 3;
	}
	else if(positions[1] == positions[3]){
		positions[0] += 3;
		// positions[1] does not change
		positions[2] += 2;
		positions[3] += 1;
		positions[4] += 1;
		positions[5] += 2;
		// positions[6] does not change
		positions[7] += 3;
	}
	
	return inRange();
}

bool IBlock::counterclockwise(int r, int c){ // r and c not needed here
	return clockwise(r, c);
}

IBlock::IBlock(int lvl) : Block(lvl, 'I'){
	positions = new int[8];
	
	positions[0] = 0;
	positions[1] = 0;
	positions[2] = 0;
	positions[3] = 1;
	positions[4] = 0;
	positions[5] = 2;
	positions[6] = 0;
	positions[7] = 3;
}
/*
IBlock::~IBlock(){
	delete [] positions;
} */
