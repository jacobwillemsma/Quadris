#ifndef __NEXTBLOCK_H__
#define __NEXTBLOCK_H__

#include <string>
#include <iostream>
#include <fstream>

class NextBlock {
	int level;
	std::string FILE_NAME;
	std::ifstream blockSeq; // name of file to read from
	int randSeed;
  
  public:
	NextBlock(int lvl, std::string fileName, int seed);
	~NextBlock();
	void addLevel();
	void subLevel();
	char getBlockType();
};

#endif
