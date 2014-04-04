#include "board.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "tblock.h"
#include "oblock.h"
#include "zblock.h"
#include "sblock.h"
#include "interpreter.h"
#include "score.h"
#include "block.h"
#include "nextblock.h"
#include "display.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {
	bool textOnly = false;
	string filename = "sequence.txt";
	int startlevel = 0;

	// Start by going through the options.
	for (int i = 0; i < argc; i++)
    {
         string arg = argv[i];
         if (arg == "-text")
         	textOnly = true;
         if (arg == "-scriptfile")
         	filename = argv[i + 1];
         if (arg == "-startlevel")
         {
            int num;
            stringstream ss(argv[i + 1]);
            ss >> num;
            startlevel = num;
         }
         /*if (arg == "-seed")
         {
            int num;
            stringstream ss(argv[i + 1]);
            ss >> num;
            srand(num);
         }*/
    }

    Interpreter *i = new Interpreter;
    if (textOnly)
    	Board *b = new Board(...); // Initiated without the xWindow chunk (or with it set to NULL)
    else
		Board *b = new Board(...); // initiated with xWindow.
	string input;
	NextBlock *nblock = new NextBlock(startlevel, filename);
	Block *b = new Block() 
	
	// Deal with the commands issued to the game.
	// Need to somehow implement current block and next block seemlessly.  Because next block needs to be known here.
	while (cin >> command) {
		if (input[0] >= 48 && input[0] <= 57) {
			// We have a number before our command.
			istringstream ss;
			int i = 0;
			int number;
			string command;
			while (input[i] >= 48 && input[i] <= 57) {
				ss << input[i];
				i++;
			}
			ss >> number;
			command = input.substr(i);
			i.multipleCommand(number, command, b);
		}
		else {
			i.processCommand(input, b);
		}
		// Print out the board every time.
		cout << b;
	}
}