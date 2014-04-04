#include "zblock.h"
#include <iostream>

using namespace std;

bool ZBlock::clockwise(int r, int c){
	if(positions[0] == r){
		// positions[0] does not change
		// positions[1] does not change
		positions[2] -= 1;
		positions[3] += 1;
		positions[4] += 2;
		// positions[5] does not change
		positions[6] += 1;
		positions[7] += 1;
	}
	else if(positions[0] == r-2){
		// positions[0] does not change
		// positions[1] does not change
		positions[2] += 1; 
		positions[3] -= 1;
		positions[4] -= 2;
		// positions[5] does not change
		positions[6] -= 1;
		positions[7] -= 1;
	}
	
	return inRange();
}

bool ZBlock::counterclockwise(int r, int c){
	return clockwise();
}

ZBlock::ZBlock(int lvl) : Block(lvl), type('Z'){
	positions = new int[8];
	
	positions[0] = 0;
	positions[1] = 0;
	positions[2] = 0;
	positions[3] = 1;
	positions[4] = 1;
	positions[5] = 1;
	positions[6] = 1;
	positions[7] = 2;
}

ZBlock::~ZBlock(){
	delete [] positions;
}
