#include "interpreter.h"
using namespace std;

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

bool Interpreter::isValid(string command) {
	return (isLeft(command) || isRight(command) || isDown(command) || isClockwise(command) || isCounterClockwise(command) || isDrop(command) || isLevelUp(command) || isLevelDown(command) || isRestart(command));
}

bool Interpreter::processCommand(string command, Block *blo, Board *b) {
	if (isValid(command)) {
		if (isLeft(command)) {
			blo->left(b);
			return true;
		}
		else if (isRight(command)) {
			blo->right(b);
			return true;
		}
		else if (isDown(command)) {
			// Move block down
			blo->down(b);
			return true;
		}
		else if (isDrop(command)) {
			// Drops the block
			blo->drop(b);
			return true;
			// Somewhere in here the game may need to end?  Maybe we'll just check seperately in the main program.
		}
		else if (isClockwise(command)) {
			// Drops the block
			blo->clockwise(b);
			return true;
		}
		else if (isCounterClockwise(command)) {
			// Drops the block
			blo->counterclockwise(b);
			return true;
		}
		else 
			return false;
	}
	else
		return false;
}