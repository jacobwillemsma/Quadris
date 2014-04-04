#ifndef __CELL_H__
#define __CELL_H__

class Cell {
	int r, c; // The row and column that the cell is.
	char symbol; // The symbol in the Cell.
	bool occupied; // True if the cell is full and false if the cell is empty.

public:
	Cell();

	bool isOccupied();
	void init(int r, int c); // sets the Cell's row and column
	void setSymbol(char newSymbol); // sets the Cell's symbol
	char getSymbol(); // returns the Cell's symbol

};

#endif