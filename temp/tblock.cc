#include "tblock.h"
#include <iostream>

using namespace std;

bool TBlock::clockwise(int r, int c){
	row = r;
	col = c;
	
	if(config == 1){ configTwo(); } // first config. to second
	else if(config == 2){ configThree(); } // second config. to third
	else if(config == 3){ configFour(); } // third config. to fourth
	else{ configOne(); } // fourth config. to first
	
	++config;
	
	return inRange();
}

bool TBlock::counterclockwise(int r, int c){
	row = r;
	col = c;
	
	if(config == 1){ configFour(); } // first config. to fourth
	else if(config == 2){ configOne(); } // second config. to first
	else if(config == 3){ configTwo(); } // third config. to second
	else{ configThree(); } // fourth config. to third
	
	--config;
	
	return inRange();
}

TBlock::TBlock(int lvl) : Block(lvl), type('J'){
	positions = new int[8];
	
	positions[0] = 0;
	positions[1] = 0;
	positions[2] = 0;
	positions[3] = 1;
	positions[4] = 1;
	positions[5] = 1;
	positions[6] = 0;
	positions[7] = 2;
}

TBlock::~TBlock(){
	delete [] positions;
}

void TBlock::configOne(){
	positions[0] = r-1;
	positions[1] = c;
	positions[2] = r-1;
	positions[3] = c+1;
	positions[4] = r;
	positions[5] = c+1;
	positions[6] = r-1;
	positions[7] = c+2;
}

void TBlock::configTwo(){
	positions[0] = r-1;
	positions[1] = c;
	positions[2] = r-2;
	positions[3] = c+1;
	positions[4] = r-1;
	positions[5] = c+1;
	positions[6] = r;
	positions[7] = c+1;
}

void TBlock::configThree(){
	positions[0] = r;
	positions[1] = c;
	positions[2] = r-1;
	positions[3] = c+1;
	positions[4] = r;
	positions[5] = c+1;
	positions[6] = r;
	positions[7] = c+2;
}

void TBlock::configFour(){
	positions[0] = r-2;
	positions[1] = c;
	positions[2] = r-1;
	positions[3] = c;
	positions[4] = r;
	positions[5] = c;
	positions[6] = r-1;
	positions[7] = c+1;
}