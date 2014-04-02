#include "nextblock.h"
#include <csstdlib> // used for rand function

using namespace std;


NextBlock::NextBlock(int lvl, string src) : level(lvl), fileName(src){}

void NextBlock::addLevel(){
	++level;
}

void NextBlock::subLevel(){
	--level;
}

char NextBlock::getBlockType(){
	int random;
	if(level == 0){
		// read from file "sequence.txt"
	}
	else if(level == 1){
		random = rand() % 12;
		
		if(random == 0)
			return 'S';
		else if(random == 1)
			return 'Z';
		else if(random == 2 || random == 3)
			return 'T';
		else if(random == 4 || random == 5)
			return 'L';
		else if(random == 6 || random == 7)
			return 'O';
		else if(random == 8 || random == 9)
			return 'I';
		else if(random == 10 || random == 11)
			return 'J';
	}
	else if(level == 2){
		random = rand() % 7;
		
		if(random == 0)
			return 'S';
		else if(random == 1)
			return 'Z';
		else if(random == 2)
			return 'T';
		else if(random == 3)
			return 'L';
		else if(random == 4)
			return 'O';
		else if(random == 5)
			return 'I';
		else if(random == 6)
			return 'J';
	}
	else if(level == 3){
		random = rand() % 9;
		
		if(random == 0)
			return 'J';
		else if(random == 1)
			return 'I';
		else if(random == 2)
			return 'T';
		else if(random == 3)
			return 'L';
		else if(random == 4)
			return 'O';
		else if(random == 5 || random == 6)
			return 'Z';
		else if(random == 7 || random == 8)
			return 'S';
	}
}


