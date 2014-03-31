#include "jblock.h"
#include <iostream>

using namespace std;


int JBlock::getLevel(){
	return level;
}

void JBlock::left(){
	// currently does nothing.. should probably be handled by Grid
}

void JBlock::right(){
	// currently does nothing.. should probably be handled by Grid
}

void JBlock::down(){
	// currently does nothing.. should probably be handled by Grid
}

void JBlock::drop(){
	// currently does nothing.. should probably be handled by Grid
}

void JBlock::clockwise(){
	if(positons[0] == 0 && positions[1] == 1 && positions[2] == 0){ configTwo(); } // first config. to second
	else if(positons[0] == 0 && positions[1] == 2){ configThree(); } // second config. to third
	else if(positons[0] == 0 && positions[1] == 2 && positions[2] == 1){ configFour(); } // third config. to fourth
	else if(positons[0] == 0 && positions[1] == 0){ configOne(); } // fourth config. to first
}

void JBlock::counterclockwise(){
	if(positons[0] == 0 && positions[1] == 1 && positions[2] == 0){ configFour(); } // first config. to fourth
	else if(positons[0] == 0 && positions[1] == 2){ configOne(); } // second config. to first
	else if(positons[0] == 0 && positions[1] == 2 && positions[2] == 1){ configTwo(); } // third config. to second
	else if(positons[0] == 0 && positions[1] == 0){ configThree(); } // fourth config. to third
}

JBlock::JBlock(int lvl) : level(lvl), type('J'){
	positions = new int[8];
	
	configOne();
}

JBlock::~JBlock(){
	delete [] positions;
}

void JBlock::configOne(){
	positions[0] = 0;
	positions[1] = 1;
	positions[2] = 0;
	positions[3] = 0;
	positions[4] = 1;
	positions[5] = 0;
	positions[6] = 2;
	positions[7] = 0;
}

void JBlock::configTwo(){
	positions[0] = 0;
	positions[1] = 2;
	positions[2] = 0;
	positions[3] = 1;
	positions[4] = 0;
	positions[5] = 0;
	positions[6] = 1;
	positions[7] = 2;
}

void JBlock::configThree(){
	positions[0] = 0;
	positions[1] = 1;
	positions[2] = 1;
	positions[3] = 1;
	positions[4] = 2;
	positions[5] = 1;
	positions[6] = 2;
	positions[7] = 0;
}

void JBlock::configFour(){
	positions[0] = 0;
	positions[1] = 0;
	positions[2] = 1;
	positions[3] = 2;
	positions[4] = 1;
	positions[5] = 1;
	positions[6] = 1;
	positions[7] = 0;
}