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
	else if (command.length() == 6)
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

bool Interpreter::isValid(string command) {
	return (isLeft(command) || isRight(command) || isDown(command) || isDrop(command));
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
		else 
			return false;
	}
	else
		return false;
}