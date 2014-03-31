#ifndef __JBLOCK_H__
#define __JBLOCK_H__

#include "block.h"


class JBlock : public Block{
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
	
	JBlock(int lvl);
	~JBlock();
};


#endif
