#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__

#include "board.h"
#include "block.h"
#include "coordinate.h"
#include "textdisplay.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Interpreter {
	bool isLeft(std::string command);
	bool isRight(std::string command);
	bool isDown(std::string command);
	bool isDrop(std::string command);
	bool isValid(std::string command);

public:
	bool processCommand(std::string command, Block *blo, Board *b);
};

#endif