#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include "board.h"
#include <iostream>
#include <string>

class Interpreter {
	bool isLeft(std::string command);
	bool isRight(std::string command);
	bool isDown(std::string command);
	bool isClockwise(std::string command);
	bool isCounterClockwise(std::string command);
	bool isDrop(std::string command);
	bool isLevelUp(std::string command);
	bool isLevelDown(std::string command);
	bool isRestart(std::string command);
	bool isValid(std::string command);

public:
	bool processCommand(std::string command, Board *b);
	bool multipleCommand(int multiplier, std::string command, Board *b);
};

#endif