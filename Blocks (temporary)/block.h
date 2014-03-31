#ifndef __BLOCK_H__
#define __BLOCK_H__

class Block{
	int level;
	char type;
	int positions[];

  public:
	// all virtual methods for the Blocks
	virtual int getLevel();
	virtual void left();
	virtual void right();
	virtual void down();
	virtual void drop();
	virtual void clockwise();
	virtual void counterclockwise();
	
	Block();
	virtual ~Block() = 0;
};


#endif
