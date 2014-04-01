#include "cell.h"

using namespace std;

Cell::Cell() : r(-1), c(-1), symbol(' '), occupied(false), numNeighbours(0){}

bool Cell::isOccupied(){
	return occupied;
}

void Cell::setSymbol(char newSymbol) {
	symbol = newSymbol;
	
	if(newSymbol != ' ') occupied = true;
	else occupied = false;
}

void Cell::init(int r, int c) {
	this->r = r;
	this->c = c;
}


void Cell::addNeighbour(Cell *neighbour){
	// adds a neighbour and increases the number of neighbours
	neighbours[numNeighbours] = neighbour;
	++numNeighbours;
}


// NEEED TO CREATE SOME KIND OF ALERT FOR WHEN THE LAST CELL IN A BLOCK IS DELETED
void Cell::notify(){
	--numNeighbours;
}

void Cell::notifyNeighbours(){
	for(int i = 0; i < numNeighbours; ++i){
		neighbours[i].notify();
	}
}


void Cell::notifyDisplay(TextDisplay td){
	td.notify(r, c, symbol);
}


bool Cell::clearCell(){
	if(symbol == ' ') // ie, the block was alredy empty
		return false;
	
	occupied = false;
	symbol = ' ';
	
	if(numNeighbours == 0)
		return true; // ie, all of the block has been deleted
	else{
		notifyNeighbours();
		numNeighbours = 0;
	}
	return false;
}