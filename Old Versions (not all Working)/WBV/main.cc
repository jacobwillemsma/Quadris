#include "board.h"
#include "block.h"
#include "iblock.h"
#include "jblock.h"
#include "tblock.h"
//#include "lblock.h"
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

int main(int argc, const char * argv[]) {

	string filename = "sequence.txt";
	Board *b = new Board();
	Interpreter *i = new Interpreter();
	/*NextBlock *nb = new NextBlock(0, filename);
	char blockname = nb->getBlockType();
	cout << "blockname has value " << blockname << endl;
	if(blockname == 'S')
        Block *blo = new sBlock(b);
    else if (blockname == 'Z')
    	Block *blo = new zBlock(b);
    else if (blockname == 'T')
        Block *blo = new tBlock(b);
    else if (blockname == 'L')
        Block *blo = new lBlock(b);
    else if (blockname == 'O')
        Block *blo = new oBlock(b);
    else if (blockname == 'I')
        Block *blo = new Block(b);
    else if (blockname == 'J')
    	Block *blo = new jBlock(b);	*/
    Block *currentBlock = new TBlock(b);
	cout << *b;
	string command;
	while (cin >> command) {
		if (i->isDrop(command)) {
			i->processCommand(command, currentBlock, b);
			//char blockname = nb->getBlockType();
			//cout << "blockname has value " << blockname << endl;
			/*if(blockname == 'S')
		        Block *blo = new sBlock(b);
		    else if (blockname == 'Z')
		    	Block *blo = new zBlock(b);
		    else if (blockname == 'T')
		        Block *blo = new tBlock(b);
		    else if (blockname == 'L')
		        Block *blo = new lBlock(b);
		    else if (blockname == 'O')
		        Block *blo = new oBlock(b);
		    else if (blockname == 'I')
		        Block *blo = new Block(b);
		    else if (blockname == 'J')
		    	Block *blo = new jBlock(b);	*/
		    //delete currentBlock;
			currentBlock = new TBlock(b);
			cout << *b;
		}
		else {
		i->processCommand(command, currentBlock, b);
		// Print out the board every time.
		cout << *b;
		}
	}
}