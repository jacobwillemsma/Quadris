#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__

#include "block.h"

class ZBlock : public Block {
	int config; // marks the current configuration of the Block
  public:
	ZBlock(Board *b);
	~ZBlock();
	
	void clockwise(Board *b);
	void counterclockwise(Board *b);
	
	void configOne(int r, int c);
	void configTwo(int r, int c);
};

#endif