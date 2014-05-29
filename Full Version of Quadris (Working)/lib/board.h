#ifndef __BOARD_H__
#define __BOARD_H__
#include "cell.h"
#include "coordinate.h"
#include "textdisplay.h"

class Board {
	int boardWidth;
	int boardHeight;
	Cell **theBoard;
	TextDisplay *td;

	bool rowFull(int r);
	void removeRow(int r);
	
public:
	Board();
	~Board();
	
	bool isOccupied(int r, int c);
	int rowsChecker();
	void clearBoard();
	void setCurrent(Coordinate *curr, char type);
	void update(int r, int c, char type);
	void updateDisplay(int lvl, int scr, int hiscr, char next);
	
	friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif