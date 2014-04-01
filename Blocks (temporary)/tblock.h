#ifndef __TBLOCK_H__
#define __TBLOCK_H__

#include "block.h"


class TBlock : public Block{
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
	
	int * getPositions();
	
	TBlock(int lvl);
	~TBlock();
};


#endif
