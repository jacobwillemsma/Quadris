#include "board.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "tblock.h"
#include "lblock.h"
#include "oblock.h"
#include "zblock.h"
#include "sblock.h"
#include "nextblock.h"
#include "interpreter.h"
#include "textdisplay.h"
#include "board.h"
#include "cell.h"
#include "score.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;


/*
This function is used to generate the required block based on
a given blockname.
*/

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
	
	// Since there are only 7 types of blocks and the input to
	// this function is restricted, the function will never 
	// return 0.
	return 0;
}


// The mainline of the program, equipped to deal with commandline arguments.
int main(int argc, const char * argv[]) {
	
	// Some default variables.
	int level = 0;
	string filename = "sequence.txt";
	int seed = time(NULL);

	// Running through the commandline arguments, updating where required.
	for (int i = 0; i < argc; i++) {
		string arg = argv[i];
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

	// Starting up the game.  We initiate from the heap all the required
	// objects to begin playing.  Some initial setip is done here.
	NextBlock *newB = new NextBlock(level, filename, seed);
	Board *b = new Board();
	Interpreter *i = new Interpreter();
	Score *scr = new Score();
	char nextBlock = newB->getBlockType();
	// If we get an 'A' back right away, this means the file had no input.  The game is automatically ended.
	if (nextBlock == 'A') {
		delete i;
		delete scr;
		delete newB;
		cout << *b;
		delete b;
		cout << "GAME OVER" << endl << endl;
		cout << "Input stream exhaused in file: \"" << filename << "\"" << endl;
		return 0;
	}
	// Else we just get an actual block from getNewBlock and pull the next block type from the NextBlock object.
    Block *currentBlock = getNewBlock(nextBlock, b, level);
    nextBlock = newB->getBlockType();
    
    // A nice little intro to Quadris.
    cout << "_____________________" << endl << endl << endl << endl;
    cout << " Welcome to Quadris! " << endl << endl;
    cout << " Commands are:       " << endl;
    cout << " left                " << endl;
    cout << " right               " << endl;
    cout << " down                " << endl;
    cout << " drop                " << endl;
    cout << " clockwise           " << endl;
    cout << " counterclockwise    " << endl;
    cout << " levelup             " << endl;
    cout << " leveldown           " << endl;
    cout << " restart             " << endl;
    cout << " exit                " << endl << endl << endl;
    cout << "_____________________" << endl << endl << endl;

    // The first of many display updates.  Let's the user see the first set up.
	b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
	cout << *b;

	// The while loop for commands.
	string command;
	while (cin >> command) {

		// If a drop was called.
		if (i->isDrop(command)) {
			i->processCommand(command, currentBlock, b);

			// Checks if the drop caused any rows to be filled and returns the number of rows removed.
			int rows = b->rowsChecker();
			
			delete currentBlock;
			// Checks if input file has been exhausted.  Program needs to terminate in this case.
			if (nextBlock == 'A') {
				delete i;
				delete scr;
				delete newB;
				cout << *b;
				delete b;
				cout << "GAME OVER" << endl;
				cout << "Input stream exhaused in file: \"" << filename << "\"" << endl;
				cout << "Thanks for playing!!!" << endl;
				return 0;
			}
			currentBlock = getNewBlock(nextBlock, b, level);
			nextBlock = newB->getBlockType();
			
			// Checks if the game is over.
			if (currentBlock->isGameOver()) {
				cout << "GAME OVER" << endl << endl;
				cout << "If you want to keep playing - type \"restart\"" << endl;
				cout << "If you are done playing - type \"exit\"" << endl;
				continue;
			}
			
			// If we cleared some rows, update the score.
			if(rows)
				scr->increaseScore(((rows+level) * (rows+level)));

			// Update the display.
			b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
			cout << *b;
		}

		// If a levelUp was called.
		else if (i->isLevelUp(command)) {

			// Makes sure we can levelUp.
			if (level < 3) {
				level++;
				newB->addLevel();
				// Grab the new level block type.
				nextBlock = newB->getBlockType();
				// Update the TextDisplay.
				b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
			}
			cout << *b;
		}

		// If a levelDown was called.
		else if (i->isLevelDown(command)) {

			// Makes sure we can levelDown.
			if (level > 0) {
				level--;
				newB->subLevel();
				// Grab the new level block type.
				nextBlock = newB->getBlockType();
				// Update the TextDisplay.
				b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
			}
			cout << *b;
		}

		// If restart was called.
		else if (i->isRestart(command)) {

			// Reset the score and board.
			scr->resetScore();
			b->clearBoard();
			delete currentBlock;

			// Grab the new required blocks.
			currentBlock = getNewBlock(nextBlock, b, level);
			nextBlock = newB->getBlockType();

			// Update the TextDisplay.
			b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
			cout << *b;
		}

		// The multiple call case. (i.e. 3ri).  This works exactly as the rest of the loop does (same
		// edge cases) however, the drop, levelUp and levelDown functions run through a for loop (based
		// on the number of repetitions specified) and preform the call that many times.
		// If you are confused at how the edge cases work - see above documentation.
		else if (isdigit(command[0])) {
			
			// Here we split the command into it's number and command part.
			int numLength = 1;
			while (isdigit(command[numLength]))
				numLength++;

			string stringNum;
			string subCommand;

			stringNum = command.substr(0, numLength);
			subCommand = command.substr(numLength);

			int num;
            stringstream ss(stringNum);
            ss >> num;

            // Edge Case 1, dropping multiple blocks at once.
            if (i->isDrop(subCommand)) {
            	for (int j = 0; j < num; j++) {
					i->processCommand(subCommand, currentBlock, b);

					int rows = b->rowsChecker(); // check if the drop caused any rows to be filled and returns the number of rows removed
					
					
					delete currentBlock;
					if (nextBlock == 'A') {
						delete i;
						delete scr;
						delete newB;
						cout << *b;
						delete b;
						cout << "GAME OVER" << endl;
						cout << "Input stream exhaused in file: \"" << filename << "\"" << endl;
						cout << "Thanks for playing!!!" << endl;
						return 0;
					}
					currentBlock = getNewBlock(nextBlock, b, level);
					nextBlock = newB->getBlockType();
					
					if (currentBlock->isGameOver())
						break;
					
					if(rows)
						scr->increaseScore(((rows+level) * (rows+level)));

					b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
				}
				cout << *b;
				if (currentBlock->isGameOver()) {
					cout << "GAME OVER" << endl;
					cout << "If you want to keep playing - type \"restart\"" << endl;
					cout << "If you are done playing - type \"exit\"" << endl;	
				}
			}

			// Edge Case 2, restart.
			else if (i->isRestart(subCommand)) {
				scr->resetScore();
				b->clearBoard();
				delete currentBlock;
				currentBlock = getNewBlock(nextBlock, b, level);
				nextBlock = newB->getBlockType();
				b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
				cout << *b;
			}

			// Edge Case 3, LevelUp.
			else if (i->isLevelUp(subCommand)) {
				for (int j = 0; j < num; j++) {
					if (level < 3) {
						level++;
						newB->addLevel();
						b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
					}
				}
				cout << *b;
			}

			// Edge Case 4, LevelDown.
			else if (i->isLevelDown(subCommand)) {
				for (int j = 0; j < num; j++) {
					if (level > 0) {
						level--;
						newB->subLevel();
						b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
					}
				}
				cout << *b;
			}

			// Regular movement case.
			else {

				// multipleCommand takes care of the repetition, so no for loop here.
				i->multipleCommand(num, subCommand, currentBlock, b);
				b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
				cout << *b;
			}
		}

		// Exit case - Leave the game.
		else if (command == "exit")
			break;

		// Just a regular movement, process accordingly.
		else {
			i->processCommand(command, currentBlock, b);
			b->updateDisplay(level, scr->getScore(), scr->getHiScore(), nextBlock);
			cout << *b;
		}
	}

	// Cleans up memory and says goodbye!
	cout << "Thanks for playing!!!" << endl;
	delete currentBlock;
	delete i;
	delete scr;
	delete newB;
	delete b;
}