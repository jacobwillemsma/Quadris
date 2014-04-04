#include "sblock.h"
#include <iostream>

using namespace std;

bool SBlock::clockwise(int r, int c){
	if(positions[0] == r){
		positions[0] -= 2;
		// positions[1] does not change
		// positions[2] does not change
		positions[3] -= 1;
		positions[4] -= 1;
		// positions[5] does not change
		positions[6] += 1;
		positions[7] -= 1;
	}
	else if(positions[0] == r-2){
		positions[0] += 2;
		// positions[1] does not change
		// positions[2] does not change
		positions[3] += 1;
		positions[4] += 1;
		// positions[5] does not change
		positions[6] -= 1;
		positions[7] += 1;
	}
	
	return inRange();
}

bool SBlock::counterclockwise(int r, int c){
	return clockwise(r, c);
}

SBlock::SBlock(int lvl) : Block(lvl, 'S'){
	positions = new int[8];
	
	positions[0] = 1;
	positions[1] = 0;
	positions[2] = 0;
	positions[3] = 1;
	positions[4] = 1;
	positions[5] = 1;
	positions[6] = 0;
	positions[7] = 2;
}

SBlock::~SBlock(){
	delete [] positions;
}
