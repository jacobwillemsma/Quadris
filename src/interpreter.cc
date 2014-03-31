#include "interpreter.h"
#include "grid.h"
#include "block.h"
using namespace std;

bool interpreter::isLeft(string command) {
	if (command.length == 3)
		return command == "lef";
	else if (command.length == 4)
		return command == "left";
	else
		return false;
}

bool interpreter::isRight(string command) {
	if (command.length == 2)
		return command == "ri";
	else if (command.length == 3)
		return command == "rig";
	else if (command.length == 4)
		return command == "righ";
	else if (command.length == 6)
		return command == "right";
	else
		return false;
}

bool interpreter::isDown(string command) {
	if (command.length == 2)
		return command == "do";
	else if (command.length == 3)
		return command == "dow";
	else if (command.length == 4)
		return command == "down";
	else
		return false;
}

bool interpreter::isClockwise(string command) {
	if (command.length == 2)
		return command == "cl";
	else if (command.length == 3)
		return command == "clo";
	else if (command.length == 4)
		return command == "cloc";
	else if (command.length == 5)
		return command == "clock";
	else if (command.length == 6)
		return command == "clockw";
	else if (command.length == 7)
		return command == "clockwi";
	else if (command.length == 8)
		return command == "clockwis";
	else if (command.length == 9)
		return command == "clockwise";
	else
		return false;
}

bool interpreter::isCounterClockwise(string command) {
	if (command.length == 2)
		return command == "co";
	else if (command.length == 3)
		return command == "cou";
	else if (command.length == 4)
		return command == "coun";
	else if (command.length == 5)
		return command == "count";
	else if (command.length == 6)
		return command == "counte";
	else if (command.length == 7)
		return command == "counter";
	else if (command.length == 8)
		return command == "counterc";
	else if (command.length == 9)
		return command == "countercl";
	else if (command.length == 10)
		return command == "counterclo";
	else if (command.length == 11)
		return command == "countercloc";
	else if (command.length == 12)
		return command == "counterclock";
	else if (command.length == 13)
		return command == "counterclockw";
	else if (command.length == 14)
		return command == "counterclockwi";
	else if (command.length == 15)
		return command == "counterclockwis";
	else if (command.length == 16)
		return command == "counterclockwise";
	else
		return false;
}

bool interpreter::isDrop(string command) {
	if (command.length == 2)
		return command == "dr";
	else if (command.length == 3)
		return command == "dro";
	else if (command.length == 4)
		return command == "drop";
	else
		return false;
}

bool interpreter::isLevelUp(string command) {
	if (command.length == 6)
		return command == "levelu";
	else if (command.length == 7)
		return command == "levelup";
	else
		return false;
}

bool interpreter::isLevelDown(string command) {
	if (command.length == 6)
		return command == "leveld";
	else if (command.length == 7)
		return command == "leveldo";
	else if (command.length == 8)
		return command == "leveldow";
	else if (command.length == 9)
		return command == "leveldown";
	else
		return false;
}

bool interpreter::isRestart(string command) {
	if (command.length == 2)
		return command == "re";
	else if (command.length == 3)
		return command == "res";
	else if (command.length == 4)
		return command == "rest";
	else if (command.length == 5)
		return command == "resta";
	else if (command.length == 6)
		return command == "restar";
	else if (command.length == 7)
		return command == "restart";
	else
		return false;
}

bool interpreter::isValid(string command) {
	return (isLeft(command) || isRight(command) || isDown(command) || isClockwise(command) || isCounterClockwise(command) || isDrop(command) || isLevelUp(command) || isLevelDown(command) || isRestart);
}

bool interpreter::processCommand(string command) {
	if (isValid(command)) {
		return false;
		if (isLeft(command)) {
			// Move block to the left
			return true;
		}
		else if (isRight(command)) {
			// Move block to the right
			return true;
		}
		else if (isDown(command)) {
			// Move block down
			return true;
		}
		else if (isClockwise(command)) {
			// Turn block clockwise
			return true;
		}
		else if (isCounterClockwise(command)) {
			// Turn block counterclockwise
			return true;
		}
		else if (isDrop(command)) {
			// Drops the block
			/*if (drop function false)
				endgame*/
			else
				return true;
		}
		else if (isLevelUp(command)) {
			// increase the level
			return true;
		}
		else if (isLevelDown(command)) {
			// Decrease the level
			return true;
		}
		else if (isRestart(command)) {
			// Restart the game
			return true;
		}
	}
	else
		return false;
}

bool interpreter::multipleCommand(int multiplier, string command) {
	if (isValid(command)) {
		if (isRestart(command)) {
			// Restart game
			return true;
		}
		else {
			for (int i = 0; i < multiplier; i++)
				processCommand(command);
			return true;
		}
	}
	else
		return false;
}