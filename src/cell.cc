#include <iostream>
#include "cell.h"
using namespace std;


class Cell {
		int r, c; // The row and column that the cell is.
		char symbol; // The symbol in the Cell.
		bool occupied; // Returns true if the cell is full and false if the cell is empty.
	public:
		Cell();
		bool isOccupied();
		void setSymbol(char symbol);
		void init(int r, int c);
};

Cell:Cell() {
	this->r = 0;
	this->c = 0;
	this->symbol = ' '; // All spaces should be a space initially.
	this->occupied = false;
}

bool Cell:isOccupied() {
	return this->occupied;
}

void Cell:setSymbol(char newSymbol) {
	this->symbol = newSymbol;
}

symbol getSymbol() {
	return this->symbol;
}

void Cell:init(int r, int c) {
	this->r = r;
	this->c = c;
	this->symbol = getSymbol();
	this->occupied = isOccupied();
}


	