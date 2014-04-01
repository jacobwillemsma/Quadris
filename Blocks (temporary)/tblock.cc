#include "tblock.h"
#include <iostream>

using namespace std;


int TBlock::getLevel(){
	return level;
}

void TBlock::left(){
	// currently does nothing.. should probably be handled by Grid
}

void TBlock::right(){
	// currently does nothing.. should probably be handled by Grid
}

void TBlock::down(){
	// currently does nothing.. should probably be handled by Grid
}

void TBlock::drop(){
	// currently does nothing.. should probably be handled by Grid
}

void TBlock::clockwise(){
	if(positons[0] == 0 && positions[1] == 1 && positions[3] == 0){ // first config. to second
		configTwo();
	}
	else if(positons[0] == 0 && positions[1] == 2){ // second config. to third
		configThree();
	}
	else if(positons[0] == 0 && positions[1] == 2 && positions[3] == 1){ // third config. to fourth
		configFour();
	}
	else if(positons[0] == 0 && positions[1] == 0){ // fourth config. to first
		configOne();
	}
}

void TBlock::counterclockwise(){
	if(positons[0] == 0 && positions[1] == 1 && positions[3] == 0){ // first config. to fourth
		configFour();
	}
	else if(positons[0] == 0 && positions[1] == 2){ // second config. to first
		configOne();
	}
	else if(positons[0] == 0 && positions[1] == 2 && positions[3] == 1){ // third config. to second
		configTwo();
	}
	else if(positons[0] == 0 && positions[1] == 0){ // fourth config. to third
		configThree();
	}
}

int * TBlock::getPositions(){
	return positions;
}

TBlock::TBlock(int lvl) : level(lvl), type('J'){
	positions = new int[8];
	
	positions[0] = 0;
	positions[1] = 0;
	positions[2] = 1;
	positions[3] = 0;
	positions[4] = 2;
	positions[5] = 1;
	positions[6] = 2;
	positions[7] = 0;
}

TBlock::~TBlock(){
	delete [] positions;
}

void TBlock::configOne(){
	positions[0] = 0;
	positions[1] = 1;
	positions[2] = 1;
	positions[3] = 1;
	positions[4] = 1;
	positions[5] = 0;
	positions[6] = 2;
	positions[7] = 1;
}

void TBlock::configTwo(){
	positions[0] = 0;
	positions[1] = 1;
	positions[2] = 1;
	positions[3] = 2;
	positions[4] = 1;
	positions[5] = 1;
	positions[6] = 1;
	positions[7] = 0;
}

void TBlock::configThree(){
	positions[0] = 0;
	positions[1] = 0;
	positions[2] = 1;
	positions[3] = 1;
	positions[4] = 1;
	positions[5] = 0;
	positions[6] = 2;
	positions[7] = 0;
}

void TBlock::configFour(){
	positions[0] = 0;
	positions[1] = 2;
	positions[2] = 0;
	positions[3] = 1;
	positions[4] = 0;
	positions[5] = 0;
	positions[6] = 1;
	positions[7] = 1;
}