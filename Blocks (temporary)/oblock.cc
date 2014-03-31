#include "oblock.h"
#include <iostream>

using namespace std;


int OBlock::getLevel(){
	return level;
}

void OBlock::left(){
	// currently does nothing.. should probably be handled by Grid
}

void OBlock::right(){
	// currently does nothing.. should probably be handled by Grid
}

void OBlock::down(){
	// currently does nothing.. should probably be handled by Grid
}

void OBlock::drop(){
	// currently does nothing.. should probably be handled by Grid
}

void OBlock::clockwise(){} // nothing happens when an OBlock is rotated

void OBlock::counterclockwise(){} // nothing happens when an OBlock is rotated

OBlock::OBlock(int lvl) : level(lvl), type('O'){
	positions = new int[8];
	
	positions[0] = 0;
	positions[1] = 1;
	positions[2] = 0;
	positions[3] = 0;
	positions[4] = 1;
	positions[5] = 1;
	positions[6] = 1;
	positions[7] = 0;
}

OBlock::~OBlock(){
	delete [] positions;
}
