#ifndef __BLOCK_H__
#define __BLOCK_H__

class Block{
  protected:
	int level; // the game level that the block was created on.
	char type; // the char representing the block
	int * positions[8]; // an array containing the y and x coordinates (one after another) of the Block's 'Cells'
	bool inRange(); // checks to make sure the Block is still in range

  public:
	int getLevel(); // returns the level that the block was created on
	bool left(); // moves the Block to the left, returns false if out of bounds, true otherwise
	bool right(); // moves the Block to the right, returns false if out of bounds, true otherwise
	bool down(); // moves the Block down, returns false if out of bounds, true otherwise
	
	char getType(); // returns the char of the block
	
	// the turning functions of the Blocks are virtual as they are different for different types of Block, returns true if a valid move
	virtual bool clockwise(int r, int c) = 0;
	virtual bool counterclockwise(int r, int c) = 0;
	
	int * getPositions(); // returns the current positions within the block
	void setPositions(int * pos); // sets the positions within the block
	
	Block(int lvl);
	virtual ~Block() = 0;
};


#endif
