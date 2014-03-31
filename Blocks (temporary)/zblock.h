#ifndef __ZBLOCK_H__
#define __ZBLOCK_H__

#include "block.h"


class ZBlock : public Block{
  public:
	int getLevel();
	void left();
	void right();
	void down();
	void drop();
	void clockwise();
	void counterclockwise();
	
	ZBlock(int lvl);
	~ZBlock();
};


#endif
