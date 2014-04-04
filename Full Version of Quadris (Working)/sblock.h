#ifndef __SBLOCK_H__
#define __SBLOCK_H__
#include "block.h"

class SBlock : public Block {
	int config;

public:
	SBlock(Board *b, int lvl);
	~SBlock();
	
	void clockwise(Board *b);
	void counterclockwise(Board *b);
	
	void configOne(int r, int c);
	void configTwo(int r, int c);
};

#endif