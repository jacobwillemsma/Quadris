#ifndef __CELL_H__
#define __CELL_H__

class Cell {
	int r, c;
	bool occupied;
	char symbol;

public:
	Cell();

	bool isOccupied();
	char getSymbol();
	void init(int r, int c);
	void setSymbol(char newSymbol);	
};

#endif