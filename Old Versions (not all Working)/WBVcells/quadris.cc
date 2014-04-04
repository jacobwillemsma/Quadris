#include "board.h"
#include "block.h"
#include "nextblock.h"
#include "iblock.h"
#include "jblock.h"
#include "tblock.h"
#include "lblock.h"
#include "oblock.h"
#include "zblock.h"
#include "sblock.h"
#include "interpreter.h"
#include "textdisplay.h"
#include "board.h"
#include "cell.h"
#include "score.h"
#include "nextblock.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

Block * getNewBlock(char blockname, Board *b, int level){
	if(blockname == 'S')
		return new SBlock(b, level);
	else if (blockname == 'Z')
		return new ZBlock(b, level);
	else if (blockname == 'T')
	    return new TBlock(b, level);
	else if (blockname == 'L')
	    return new LBlock(b, level);
	else if (blockname == 'O')
	    return new OBlock(b, level);
	else if (blockname == 'I')
	    return new IBlock(b, level);
	else if (blockname == 'J')
		return new JBlock(b, level);
	
	return 0;
}

int main(int argc, const char * argv[]) {
	bool textOnly = true;
	int level = 0;
	string filename = "sequence.txt";
	int seed = time(NULL);

	for (int i = 0; i < argc; i++) {
		string arg = argv[i];
		if (arg == "-text")
			textOnly = true;
		if (arg == "-scriptfile")
			filename = argv[i + 1];
		if (arg == "-startlevel") {
			int num;
            stringstream ss(argv[i + 1]);
            ss >> num;
            if (num >= 0 && num <=3)
            	level = num;
		}
		if (arg == "-seed") {
            stringstream ss(argv[i + 1]);
            ss >> seed;
		}
	}

	NextBlock *newB = new NextBlock(level, filename, seed);
	Board *b = new Board();
	Interpreter *i = new Interpreter();
	Score *scr = new Score();
    Block *currentBlock = getNewBlock(newB->getBlockType(), b, level);
    char nextBlock = newB->getBlockType();
    
	b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
	
	cout << *b;
	string command;
	while (cin >> command) {
		if (i->isDrop(command)) {
			i->processCommand(command, currentBlock, b);
			//char blockname = nb->getBlockType();
			//cout << "blockname has value " << blockname << endl;
			int rows = b->rowsChecker(); // check if the drop caused any rows to be filled and returns the number of rows removed
			
			currentBlock = getNewBlock(nextBlock, b, level);
			nextBlock = newB->getBlockType();
			
			if (currentBlock->isGameOver()){
				cout << endl << endl << "GAME OVER" << endl << endl;
				break;
			}
			
			if(rows)
				scr->increaseScore(((rows+level) * (rows+level)));
			b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
			cout << *b;
		}
		else if (i->isLevelUp(command)) {
			if (level < 3) {
				level++;
				newB->addLevel();
				b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
			}
			cout << *b;
		}
		else if (i->isLevelDown(command)) {
			if (level > 0) {
				level--;
				newB->subLevel();
				b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
			}
			cout << *b;
		}
		else if (i->isRestart(command)) {
			scr->resetScore();
			b->clearBoard();
			currentBlock = getNewBlock(nextBlock, b, level);
			nextBlock = newB->getBlockType();
			b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
			cout << *b;
		}

		else {
			i->processCommand(command, currentBlock, b);
			// Print out the board every time.
			b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
			cout << *b;
		}
	}
	delete b;
	delete currentBlock;
	delete i;
	delete scr;
	delete newB;
	//cout << *b; do we want this??
}