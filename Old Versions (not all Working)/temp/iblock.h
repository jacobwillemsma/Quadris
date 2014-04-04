#ifndef __IBLOCK_H__
#define __IBLOCK_H__

#include "block.h"


class IBlock : public Block{
  public:
	bool clockwise(int r, int c);
	bool counterclockwise(int r, int c);
	
	IBlock(int lvl);
	~IBlock();
};


#endif
