#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include "block.h"
#include "board.h"
#include <iostream>
#include <string>

class Interpreter {
	bool isLeft(std::string command);
	bool isRight(std::string command);
	bool isDown(std::string command);
	bool isClockwise(std::string command);
	bool isCounterClockwise(std::string command);
	bool isRestart(std::string command);
	bool isValid(std::string command);

public:
	bool isLevelUp(std::string command);
	bool isLevelDown(std::string command);
	bool isDrop(std::string command);
	bool processCommand(std::string command, Block *blo, Board *b);
};

#endif