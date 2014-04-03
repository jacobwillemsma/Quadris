#include "cell.h"

using namespace std;

Cell::Cell() : r(-1), c(-1), symbol(' '), occupied(false) {}

bool Cell::isOccupied(){
	return occupied;
}

void Cell::setSymbol(char newSymbol) {
	symbol = newSymbol;
	
	if (newSymbol != ' ') occupied = true;
	else occupied = false;
}

char Cell::getSymbol(){
	return symbol;
}

void Cell::init(int r, int c) {
	this->r = r;
	this->c = c;
}