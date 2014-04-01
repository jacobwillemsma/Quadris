#ifndef __SBLOCK_H__
#define __SBLOCK_H__

#include "block.h"


class SBlock : public Block{
  public:
	int getLevel();
	void left();
	void right();
	void down();
	void drop();
	void clockwise();
	void counterclockwise();
	
	int * getPositions();
	
	SBlock(int lvl);
	~SBlock();
};


#endif
