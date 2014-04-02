#ifndef __NEXTBLOCK_H__
#define __NEXTBLOCK_H__

#include <string>

class NextBlock {
	int level;
	std::string fileName; // name of file to read from
  
  public:
	NextBlock(int lvl, std::string src);
	void addLevel();
	void subLevel();
	char getBlockType();
};

#endif
