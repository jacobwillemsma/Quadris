#ifndef __LBLOCK_H__
#define __LBLOCK_H__	

#include "block.h"

class LBlock : public Block {
	int config; // marks the current configuration of the Block
public:
	LBlock(Board *b, int lvl);
	~LBlock();

	void clockwise(Board *b);
	void counterclockwise(Board *b);

	void configOne(int r, int c);
	void configTwo(int r, int c);
	void configThree(int r, int c);
	void configFour(int r, int c);
};

#endif
