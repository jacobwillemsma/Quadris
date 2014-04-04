#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#include <iostream>
#include <string>

class Interpreter {
	bool isLeft(string command);
	bool isRight(string command);
	bool isDown(string command);
	bool isClockwise(string command);
	bool isCounterClockwise(string command);
	bool isDrop(string command);
	bool isLevelUp(string command);
	bool isLevelDown(string command);
	bool isRestart(string command);
	bool isValid(string command);

public:
	bool processCommand(string command);
	bool multipleCommand(int multiplier, string command);
};

#endif