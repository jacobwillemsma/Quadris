#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__

#include "block.h"


class ZBlock : public Block{
  public:
	bool clockwise(int r, int c);
	bool counterclockwise(int r, int c);
	
	ZBlock(int lvl);
	~ZBlock();
};


#endif
