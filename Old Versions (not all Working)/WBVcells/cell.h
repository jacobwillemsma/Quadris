#ifndef __CELL_H__
#define __CELL_H__

const int maxNeighbours = 3;

class Cell {
	int r, c; // The row and column that the cell is.
	char symbol; // The symbol in the Cell.
	bool occupied; // True if the cell is full and false if the cell is empty.
	
	bool hasNeighbours; // true only after Cell is part of a dropped Block
	bool clearedBlock; // true when a full block is cleared
	int numNeighbours; // number of neighbours
	Cell *neighbours[maxNeighbours]; // array of members

public:
	Cell();

	bool isOccupied();
	void init(int r, int c); // sets the Cell's row and column
	void setSymbol(char newSymbol); // sets the Cell's symbol
	char getSymbol(); // returns the Cell's symbol
	
	void addNeighbour(Cell *neighbour); // adds a neighbour to the Cell
	void notify(); // neighbours called this when cleared
	void notifyNeighbours(); // alerts neighbours when Cell is cleared
};

#endif