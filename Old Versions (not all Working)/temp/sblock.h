#ifndef __SBLOCK_H__
#define __SBLOCK_H__

#include "block.h"


class SBlock : public Block{
  public:
	bool clockwise(int r, int c);
	bool counterclockwise(int r, int c);
	
	SBlock(int lvl);
	~SBlock();
};


#endif
