#include "nextblock.h"
using namespace std;


/*
Constructor and Destructor.
*/

NextBlock::NextBlock(int lvl, string fileName, int seed) {

	// The constructor needs to set all of the fields and open up the file.
	randSeed = seed;
	level = lvl;
	FILE_NAME = fileName;
	srand(randSeed);
	// open the input file.
	blockSeq.open(FILE_NAME.c_str());
}

NextBlock::~NextBlock() {

	// The destructor needs to close the file.
	blockSeq.close();
}


/*
The following two methods are uses to increase and decrease the level respectively.
*/

void NextBlock::addLevel() {
	++level;
}

void NextBlock::subLevel() {
	--level;
}


/*
The following method is the core of the NextBlock class.
Depending on what level the game of Quadris is in, this method will either pull the 
next block from the sequence.txt file or randomly.
This method outputs the charactor of the next Block... this will be used for creating
the right next block and to display the next block in the TextDisplay.
*/

char NextBlock::getBlockType(){
	
	int random;
	// Read from the sequence file.
	if(level == 0){
		string type;
		if (blockSeq >> type) {
            if(type == "S")
                return 'S';
            else if (type == "Z")
                return 'Z';
            else if (type == "T")
                return 'T';
            else if(type == "L")
                return 'L';
            else if(type == "O")
                return 'O';
            else if(type == "I")
                return 'I';
            else
                return 'J';
		}
		else
			 return 'A'; // Signals that we hit EOF.
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
	// As the levels are stricly capped between 0 and 3, this should never occur.
	return 0;
}