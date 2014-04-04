#ifndef __OBLOCK_H__
#define __OBLOCK_H__

#include "block.h"


class OBlock : public Block{
  public:
	bool clockwise(int r, int c);
	bool counterclockwise(int r, int c);
	
	OBlock(int lvl);
	~OBlock();
};


#endif
