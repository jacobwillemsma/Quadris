#ifndef __LBLOCK_H__
#define __LBLOCK_H__

#include "block.h"


class LBlock : public Block{
	void configOne();
	void configTwo();
	void configThree();
	void configFour();
  public:
	int getLevel();
	void left();
	void right();
	void down();
	void drop();
	void clockwise();
	void counterclockwise();
	
	LBlock(int lvl);
	~LBlock();
};


#endif
