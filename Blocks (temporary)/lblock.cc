#include "lblock.h"
#include <iostream>

using namespace std;


int LBlock::getLevel(){
	return level;
}

void LBlock::left(){
	// currently does nothing.. should probably be handled by Grid
}

void LBlock::right(){
	// currently does nothing.. should probably be handled by Grid
}

void LBlock::down(){
	// currently does nothing.. should probably be handled by Grid
}

void LBlock::drop(){
	// currently does nothing.. should probably be handled by Grid
}

void LBlock::clockwise(){
	if(positons[0] == 0 && positions[1] == 0){ configTwo(); } // first config. to second
	else if(positons[0] == 0 && positions[1] == 2 && positiosn[2] == 0){ configThree(); } // second config. to third
	else if(positons[0] == 0 && positions[1] == 1){ configFour(); } // third config. to fourth
	else if(positons[0] == 0 && positions[1] == 0 && positiosn[2] == 1){ configOne(); } // fourth config. to first
}

void LBlock::counterclockwise(){
	if(positons[0] == 0 && positions[1] == 1){ configFour(); } // first config. to fourth
	else if(positons[0] == 0 && positions[1] == 2 && positiosn[2] == 0){ configOne(); } // second config. to first
	else if(positons[0] == 0 && positions[1] == 2){ configTwo(); } // third config. to second
	else if(positons[0] == 0 && positions[1] == 0 && positiosn[2] == 1){ configThree(); } // fourth config. to third
}

LBlock::LBlock(int lvl) : level(lvl), type('J'){
	positions = new int[8];
	
	configOne();
}

LBlock::~LBlock(){
	delete [] positions;
}

void LBlock::configOne(){
	positions[0] = 0;
	positions[1] = 0;
	positions[2] = 1;
	positions[3] = 0;
	positions[4] = 2;
	positions[5] = 1;
	positions[6] = 2;
	positions[7] = 0;
}

void LBlock::configTwo(){
	positions[0] = 0;
	positions[1] = 2;
	positions[2] = 0;
	positions[3] = 1;
	positions[4] = 0;
	positions[5] = 0;
	positions[6] = 1;
	positions[7] = 0;
}

void LBlock::configThree(){
	positions[0] = 0;
	positions[1] = 1;
	positions[2] = 0;
	positions[3] = 0;
	positions[4] = 1;
	positions[5] = 1;
	positions[6] = 2;
	positions[7] = 1;
}

void LBlock::configFour(){
	positions[0] = 0;
	positions[1] = 2;
	positions[2] = 1;
	positions[3] = 2;
	positions[4] = 1;
	positions[5] = 1;
	positions[6] = 1;
	positions[7] = 0;
}