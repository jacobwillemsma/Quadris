#ifndef __TBLOCK_H__
#define __TBLOCK_H__
#include "block.h"

class TBlock : public Block {
	int config;

public:
	TBlock(Board *b, int lvl);
	~TBlock();
	
	void clockwise(Board *b);
	void counterclockwise(Board *b);
	
	void configOne(int r, int c);
	void configTwo(int r, int c);
	void configThree(int r, int c);
	void configFour(int r, int c);
};

#endif