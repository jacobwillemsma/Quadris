#ifndef __LBLOCK_H__
#define __LBLOCK_H__

#include "block.h"


class LBlock : public Block{
	int config;
	void configOne();
	void configTwo();
	void configThree();
	void configFour();
  public:
	bool clockwise(int r, int c);
	bool counterclockwise(int r, int c);
	
	LBlock(int lvl);
	~LBlock();
};


#endif
