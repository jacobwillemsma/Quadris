#ifndef __OBLOCK_H__
#define __OBLOCK_H__

#include "block.h"


class OBlock : public Block{
  public:
	int getLevel();
	void left();
	void right();
	void down();
	void drop();
	void clockwise();
	void counterclockwise();
	
	OBlock(int lvl);
	~OBlock();
};


#endif
