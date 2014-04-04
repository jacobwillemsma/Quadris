#ifndef __JBLOCK_H__
#define __JBLOCK_H__
#include "block.h"

class JBlock : public Block {
	int config;

public:
	JBlock(Board *b, int lvl);
	~JBlock();
	
	void clockwise(Board *b);
	void counterclockwise(Board *b);
	
	void configOne(int r, int c);
	void configTwo(int r, int c);
	void configThree(int r, int c);
	void configFour(int r, int c);
};

#endif