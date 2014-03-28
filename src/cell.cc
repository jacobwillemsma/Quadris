#include "cell.h"
#include <iostream>

using namespace std;

Cell::Cell() {
	this->r = 0;
	this->c = 0;
	this->symbol = ' '; // All characters should be a space initially.
	this->occupied = false;
}

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
	this->symbol = getSymbol();
	this->occupied = isOccupied();
}