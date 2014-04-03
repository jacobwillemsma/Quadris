#ifndef __JBLOCK_H__
#define __JBLOCK_H__

#include "block.h"

class JBlock : public Block {
	int config; // marks the current configuration of the Block
  public:
	JBlock(Board *b, int level);
	~JBlock();
	
	void clockwise(Board *b);
	void counterclockwise(Board *b);
	void updatePositions();
	
	void configOne(int r, int c);
	void configTwo(int r, int c);
	void configThree(int r, int c);
	void configFour(int r, int c);
};

#endif