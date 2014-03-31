#ifndef __CELL_H__
#define __CELL_H__

class Cell {
	int r, c; // The row and column that the cell is.
	char symbol; // The symbol in the Cell.
	bool occupied; // Returns true if the cell is full and false if the cell is empty.
  public:
	Cell();
	bool isOccupied();
	void setSymbol(char newSymbol);
	char getSymbol();
	void init(int r, int c);
};

#endif