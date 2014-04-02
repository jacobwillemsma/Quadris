#include "oblock.h"
#include <iostream>

using namespace std;

bool OBlock::clockwise(int r, int c){ return true; } // nothing happens when an OBlock is rotated

bool OBlock::counterclockwise(int r, int c){ return true; } // nothing happens when an OBlock is rotated

OBlock::OBlock(int lvl) : Block(lvl), type('O'){
	positions = new int[8];
	
	positions[0] = 0;
	positions[1] = 0;
	positions[2] = 1;
	positions[3] = 0;
	positions[4] = 0;
	positions[5] = 1;
	positions[6] = 1;
	positions[7] = 1;
}

OBlock::~OBlock(){
	delete [] positions;
}
