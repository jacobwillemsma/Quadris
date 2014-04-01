#ifndef __JBLOCK_H__
#define __JBLOCK_H__

#include "block.h"


class JBlock : public Block{
	int row; // bottom left row
	int col; // bottom left column
	
	
	int config; // marks the current configuration of the Block
	void configOne();
	void configTwo();
	void configThree();
	void configFour();
  public:
	bool clockwise(int r, int c);
	bool counterclockwise(int r, int c);
	
	JBlock(int lvl);
	~JBlock();
};


#endif
