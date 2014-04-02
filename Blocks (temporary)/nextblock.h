#ifndef __NEXTBLOCK_H__
#define __NEXTBLOCK_H__

#include <string>

class NextBlock {
	int level;
	const std::string FILE_NAME = "sequence.txt"; // name of file to read from
  
  public:
	NextBlock(int lvl);
	void addLevel();
	void subLevel();
	char getBlockType();
};

#endif
