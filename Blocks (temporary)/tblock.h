#ifndef __TBLOCK_H__
#define __TBLOCK_H__

#include "block.h"


class TBlock : public Block{
	int config;
	void configOne();
	void configTwo();
	void configThree();
	void configFour();
  public:
	bool clockwise(int r, int c);
	bool counterclockwise(int r, int c);
	
	TBlock(int lvl);
	~TBlock();
};


#endif
