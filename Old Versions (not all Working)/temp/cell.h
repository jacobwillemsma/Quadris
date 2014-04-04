#ifndef __CELL_H__
#define __CELL_H__

#include "textdisplay.h"

const int maxNeighbours = 3;

class Cell {
	int r, c; // The row and column that the cell is.
	char symbol; // The symbol in the Cell.
	bool occupied; // True if the cell is full and false if the cell is empty.
	
	int numNeighbours; // number of neighbours
	Cell *neighbours[maxNeighbours]; // array of members
	
  public:
	Cell();
	
	bool isOccupied(); // returns 'occupied'
	void setSymbol(char newSymbol); // sets the Cell's symbol
	char getSymbol(); // gets the Cell's symbol
	void init(int r, int c); // sets the Cell's row and column
	
	void addNeighbour(Cell *neighbour); // adds a neighbour to the Cell
	void notify(); // neighbours called this when cleared
	void notifyNeighbours(); // alerts neighbours when Cell is cleared
	
	void notifyDisplay(TextDisplay &td); // alerts the display to changes at the Cell
	
	bool clearCell(); // clears the Cell, notifies neighbours (if any) and returns true if this is the last neighbour of a block
};

#endif