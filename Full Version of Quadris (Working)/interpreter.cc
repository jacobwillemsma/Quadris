#include "interpreter.h"
using namespace std;


/*
The following methods are predicates to check if a command is any one of the valid
ones the application understands.  It does so by checking if it matches any of the 
required commands.  If it does, then the method returns true, false if not.
*/

bool Interpreter::isLeft(string command) {
	if (command.length() == 3)
		return command == "lef";
	else if (command.length() == 4)
		return command == "left";
	else
		return false;
}

bool Interpreter::isRight(string command) {
	if (command.length() == 2)
		return command == "ri";
	else if (command.length() == 3)
		return command == "rig";
	else if (command.length() == 4)
		return command == "righ";
	else if (command.length() == 5)
		return command == "right";
	else
		return false;
}

bool Interpreter::isDown(string command) {
	if (command.length() == 2)
		return command == "do";
	else if (command.length() == 3)
		return command == "dow";
	else if (command.length() == 4)
		return command == "down";
	else
		return false;
}

bool Interpreter::isClockwise(string command) {
	if (command.length() == 2)
		return command == "cl";
	else if (command.length() == 3)
		return command == "clo";
	else if (command.length() == 4)
		return command == "cloc";
	else if (command.length() == 5)
		return command == "clock";
	else if (command.length() == 6)
		return command == "clockw";
	else if (command.length() == 7)
		return command == "clockwi";
	else if (command.length() == 8)
		return command == "clockwis";
	else if (command.length() == 9)
		return command == "clockwise";
	else
		return false;
}

bool Interpreter::isCounterClockwise(string command) {
	if (command.length() == 2)
		return command == "co";
	else if (command.length() == 3)
		return command == "cou";
	else if (command.length() == 4)
		return command == "coun";
	else if (command.length() == 5)
		return command == "count";
	else if (command.length() == 6)
		return command == "counte";
	else if (command.length() == 7)
		return command == "counter";
	else if (command.length() == 8)
		return command == "counterc";
	else if (command.length() == 9)
		return command == "countercl";
	else if (command.length() == 10)
		return command == "counterclo";
	else if (command.length() == 11)
		return command == "countercloc";
	else if (command.length() == 12)
		return command == "counterclock";
	else if (command.length() == 13)
		return command == "counterclockw";
	else if (command.length() == 14)
		return command == "counterclockwi";
	else if (command.length() == 15)
		return command == "counterclockwis";
	else if (command.length() == 16)
		return command == "counterclockwise";
	else
		return false;
}

bool Interpreter::isDrop(string command) {
	if (command.length() == 2)
		return command == "dr";
	else if (command.length() == 3)
		return command == "dro";
	else if (command.length() == 4)
		return command == "drop";
	else
		return false;
}

bool Interpreter::isLevelUp(string command) {
	if (command.length() == 6)
		return command == "levelu";
	else if (command.length() == 7)
		return command == "levelup";
	else
		return false;
}

bool Interpreter::isLevelDown(string command) {
	if (command.length() == 6)
		return command == "leveld";
	else if (command.length() == 7)
		return command == "leveldo";
	else if (command.length() == 8)
		return command == "leveldow";
	else if (command.length() == 9)
		return command == "leveldown";
	else
		return false;
}

bool Interpreter::isRestart(string command) {
	if (command.length() == 2)
		return command == "re";
	else if (command.length() == 3)
		return command == "res";
	else if (command.length() == 4)
		return command == "rest";
	else if (command.length() == 5)
		return command == "resta";
	else if (command.length() == 6)
		return command == "restar";
	else if (command.length() == 7)
		return command == "restart";
	else
		return false;
}


/*
The following method returns true if the command is any one of the acceptable commands.
*/

bool Interpreter::isValid(string command) {
	return (isLeft(command) || isRight(command) || isDown(command) || isClockwise(command) || isCounterClockwise(command) || isDrop(command) || isLevelUp(command) || isLevelDown(command) || isRestart(command));
}


/*
The following method is for processing a single command.
*/

void Interpreter::processCommand(string command, Block *blo, Board *b) {

	// If the command is valid, then process the command on the board.
	if (isValid(command)) {
		if (isLeft(command))
			blo->left(b);
		else if (isRight(command))
			blo->right(b);
		else if (isDown(command))
			blo->down(b);
		else if (isDrop(command))
			blo->drop(b);
		else if (isClockwise(command))
			blo->clockwise(b);
		else if (isCounterClockwise(command))
			blo->counterclockwise(b);
	}
}

/*
The following method is for processing a number first command.
*/

void Interpreter::multipleCommand(int multiplier, string command, Block *blo, Board *b) {
	if (isValid(command)) {
		for (int i = 0; i < multiplier; i++)
			processCommand(command, blo, b);
	}
}