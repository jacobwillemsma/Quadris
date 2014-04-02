#include "board.h"
#include "block.h"
#include "interpreter.h"
#include "textdisplay.h"
#include "board.h"
#include "cell.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[]) {

	Board *b = new Board();
	Interpreter *i = new Interpreter();
	Block *blo = new Block(b);
	

	string command;
	while (cin >> command) {
		i->processCommand(command, blo, b);
		// Print out the board every time.
		cout << *b;
	}
}