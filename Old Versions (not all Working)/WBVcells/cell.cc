#include "cell.h"

Cell::Cell() : r(-1), c(-1), symbol(' '), occupied(false), hasNeighbours(false), clearedBlock(false) {}

bool Cell::isOccupied(){
	return occupied;
}

void Cell::setSymbol(char newSymbol) {
	symbol = newSymbol;
	
	if (newSymbol != ' ') occupied = true;
	else{
		if(hasNeighbours && numNeighbours == 0){
			clearedBlock = true;
		}
		occupied = false;
	}
}

char Cell::getSymbol(){
	return symbol;
}

void Cell::init(int r, int c) {
	this->r = r;
	this->c = c;
}

void Cell::addNeighbour(Cell *neighbour){
	hasNeighbours(true);
	// adds a neighbour and increases the number of neighbours
	neighbours[numNeighbours] = neighbour;
	++numNeighbours;
}

void Cell::notify(){
	--numNeighbours;
}

void Cell::notifyNeighbours(){
	for(int i = 0; i < numNeighbours; ++i){
		neighbours[i].notify();
	}
}

bool Cell::blockCleared(){
	if(clearedBlock){
		clearedBlock = false;
		return true;
	}
	return false;
}