#include "cell.h"


/*
Constructor.
*/

Cell::Cell() : r(-1), c(-1), occupied(false), symbol(' ') {}


/*
The following two methods are in charge of accessing the private fields of
Cell for use by other objects.  They fetch the Symbol representing the
type of block stored there and if the block is occupied, respectively.
*/

char Cell::getSymbol() {
	return symbol;
}

bool Cell::isOccupied() {
	return occupied;
}


/*
The following method is used to set the symbol of the cell.  Called when a block
is in a location on the board.
*/

void Cell::setSymbol(char newSymbol) {
	
	symbol = newSymbol;
	
	// If the newSymbol is a space, then we have just emptied the cell, thus occupied is not false.
	if (newSymbol != ' ') 
		occupied = true;
	else occupied = false;
}


/*
The following method is used to initiate the row and column that the cell is occuping.  \
Used during board initialization.
*/

void Cell::init(int r, int c) {
	this->r = r;
	this->c = c;
}