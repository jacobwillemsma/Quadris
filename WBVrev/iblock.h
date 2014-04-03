#ifndef __IBLOCK_H__
#define __IBLOCK_H__

#include "block.h"

class IBlock : public Block {
  public:
	IBlock(Board *b, int level);
	~IBlock();
	
	void clockwise(Board *b);
	void counterclockwise(Board *b);
};

#endif