#include "lblock.h"
#include <iostream>

using namespace std;

bool LBlock::clockwise(int r, int c){
	row = r;
	col = c;
	
	if(config == 1){ configTwo(); } // first config. to second
	else if(config == 2){ configThree(); } // second config. to third
	else if(config == 3){ configFour(); } // third config. to fourth
	else{ configOne(); } // fourth config. to first
	
	++config;
	
	return inRange();
}

bool LBlock::counterclockwise(int r, int c){
	row = r;
	col = c;
	
	if(config == 1){ configFour(); } // first config. to fourth
	else if(config == 2){ configOne(); } // second config. to first
	else if(config == 3){ configTwo(); } // third config. to second
	else{ configThree(); } // fourth config. to third
	
	--config;
	
	return inRange();
}

LBlock::LBlock(int lvl) : Block(lvl, 'L'){
	positions = new int[8];
	config = 1;
	row = 1;
	col = 0;
	
	positions[0] = 1;
	positions[1] = 0;
	positions[2] = 1;
	positions[3] = 1;
	positions[4] = 0;
	positions[5] = 2;
	positions[6] = 1;
	positions[7] = 2;
}

LBlock::~LBlock(){
	delete [] positions;
}

void LBlock::configOne(){
	positions[0] = row;
	positions[1] = col;
	positions[2] = row;
	positions[3] = col+1;
	positions[4] = row-1;
	positions[5] = col+2;
	positions[6] = row;
	positions[7] = col+2;
}

void LBlock::configTwo(){
	positions[0] = row-2;
	positions[1] = col;
	positions[2] = row-1;
	positions[3] = col;
	positions[4] = row;
	positions[5] = col;
	positions[6] = row;
	positions[7] = col+1;
}

void LBlock::configThree(){
	positions[0] = row-1;
	positions[1] = col;
	positions[2] = row;
	positions[3] = col;
	positions[4] = row-1;
	positions[5] = col+1;
	positions[6] = row-1;
	positions[7] = col+2;
}

void LBlock::configFour(){
	positions[0] = row-2;
	positions[1] = col;
	positions[2] = row-2;
	positions[3] = col+1;
	positions[4] = row-1;
	positions[5] = col+1;
	positions[6] = row;
	positions[7] = col+1;
}