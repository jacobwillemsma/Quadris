#ifndef __IBLOCK_H__
#define __IBLOCK_H__

#include "block.h"


class IBlock : public Block{
  public:
	int getLevel();
	void left();
	void right();
	void down();
	void drop();
	void clockwise();
	void counterclockwise();
	
	IBlock(int lvl);
	~IBlock();
};


#endif
