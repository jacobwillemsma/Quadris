#include "cell.h"

using namespace std;

Cell::Cell() : r(0), c(0), symbol(' '), occupied(false){} // all characters should be a space initially

bool Cell::isOccupied() {
	return this->occupied;
}

void Cell::setSymbol(char newSymbol) {
	symbol = newSymbol;
	
	if(newSymbol != ' ') occupied = true;
	else occupied = false;
}

char Cell::getSymbol() {
	return this->symbol;
}

void Cell::init(int r, int c) {
	this->r = r;
	this->c = c;
}