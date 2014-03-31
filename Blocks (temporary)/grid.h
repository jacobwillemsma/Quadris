#ifndef __GRID_H__
#define __GRID_H__

#include "cell.h"
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "tblock.h"
#include "oblock.h"
#include "zblock.h"
#include "sblock.h"
#include "display.h"
//#include "xwindow.h"
#include <iostream>

class Grid {
	Cell **board;
	Block current;
	Block next;
	const int boardHeight = 15;
	const int boardWidth = 10;
	Display *d;
	//XWindow *xw;
	
	void clearGrid();
	void clearRow(int r);
	void gameStart();
	void lineCheck();
	void rowFull();
	void removeRow(int r);
	bool isFull(int r, int c);
	
	bool gameOver(); // will return true if the next Block is not able to enter the board
	
	Block getBlock(string b); // returns a block
	Block getRandBlock(); // returns a 'random' block
	
  public:
	Grid();
	~Grid();
	
	void down();
	void drop();
	void left();
	void right();
	
	
	Cell getLocation(int r, int c);
	bool canPlay();
	void restartGame();
	
	friend std::ostream &operator<<(std::ostream &out, Grid g);
};

#endif