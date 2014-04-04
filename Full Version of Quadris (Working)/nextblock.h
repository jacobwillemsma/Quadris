#ifndef __NEXTBLOCK_H__
#define __NEXTBLOCK_H__

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class NextBlock {
	int level;
	std::string FILE_NAME;
	std::ifstream blockSeq;
	int randSeed;
  
public:
	NextBlock(int lvl, std::string fileName, int seed);
	~NextBlock();

	char getBlockType();
	void addLevel();
	void subLevel();
};

#endif
