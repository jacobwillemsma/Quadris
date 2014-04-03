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
#include "nextblock.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

Block * getNewBlock(char blockname, Board *b){
	if(blockname == 'S')
		return new SBlock(b);
	else if (blockname == 'Z')
		return new ZBlock(b);
	else if (blockname == 'T')
	    return new TBlock(b);
	else if (blockname == 'L')
	    return new LBlock(b);
	else if (blockname == 'O')
	    return new OBlock(b);
	else if (blockname == 'I')
	    return new IBlock(b);
	else if (blockname == 'J')
		return new JBlock(b);
	
	return 0;
}

int main(int argc, const char * argv[]) {
	int level = 1; //temporary
	string filename = "sequence.txt";
	NextBlock *newB = new NextBlock(level, filename);
	Board *b = new Board();
	Interpreter *i = new Interpreter();
    Block *currentBlock = getNewBlock(newB->getBlockType(), b);
    char nextBlock = newB->getBlockType();
    
	b->updateDisplay(level, 100, 100, nextBlock);
	cout << *b;
	string command;
	while (cin >> command) {
		if (i->isDrop(command)) {
			i->processCommand(command, currentBlock, b);
			//char blockname = nb->getBlockType();
			//cout << "blockname has value " << blockname << endl;
			b->rowsChecker(); // check if the drop caused any rows to be filled
			
			currentBlock = getNewBlock(nextBlock, b);
			nextBlock = newB->getBlockType();
			
			if (currentBlock->isGameOver()){
				cout << "GAME OVER" << endl;
				break;
			}
			
			b->updateDisplay(level, 100, 100, nextBlock);
			cout << *b;
		}
		else {
		i->processCommand(command, currentBlock, b);
		// Print out the board every time.
			b->updateDisplay(level, 100, 100, nextBlock);
			cout << *b;
		}
	}
}