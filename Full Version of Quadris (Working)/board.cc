#include "board.h"
using namespace std;


/*
Constructor and Destructor.
*/

Board::Board() {

	// Set constants.
	boardWidth = 10;
	boardHeight = 18;
	td = new TextDisplay(boardHeight, boardWidth);

	// Initiate the board and fill it with newly initiated Cell objects.
	theBoard = new Cell *[boardHeight];
    for (int i = 0; i < boardHeight; i++)
        this->theBoard[i] = new Cell[this->boardWidth];
	for (int i = 0; i < this->boardHeight; i++) {
		for (int j = 0; j < this->boardWidth; j++) {
			theBoard[i][j].init(i, j);
		}
	}
}

Board::~Board() {

	// Delete all the Cells.
	for(int i = 0; i < boardHeight; ++i){
		delete [] theBoard[i];
	}

	// Delete the board and the TextDisplay.
	delete [] theBoard;
	delete td;
}


/*
These two methods are used for checking if a row is full and to clear it, respectively.
They are used to deal with the case of a full line in Quadris.
*/

bool Board::rowFull(int r){

	for(int i = 0; i < boardWidth; ++i) {
		if(!isOccupied(r, i)) 
			return false;
	}
	return true;
}

void Board::removeRow(int r) {

	// Copy the rows above down.
	for(int i = r; i > 1; --i){
		for(int j = 0; j < boardWidth; ++j){
			theBoard[i][j].setSymbol(theBoard[i-1][j].getSymbol());
			td->notify(i, j, theBoard[i-1][j].getSymbol());
		}
	}
}


/*
This method is in charge of clearing a board, used during restart.
*/

void Board::clearBoard() {

	// clears the Board by deleting all Cells
	for(int i = 0; i < boardHeight; ++i){
		for(int j = 0; j < boardWidth; ++j){
			theBoard[i][j].setSymbol(' ');
			td->notify(i, j, ' ');
		}
	}
}


/*
Returns if something is in the cell, true is yes, false else wise.
*/

bool Board::isOccupied(int r, int c) {
	return theBoard[r][c].isOccupied();
}


/*
This method is called to update the cell at postision (r,c).  
It also simultaneously updates the TextDisplay at the same location.
*/

void Board::update(int r, int c, char type) {
	
	theBoard[r][c].setSymbol(type);
	td->notify(r, c, type);
}

/*
This method runs through the board and returns how many rows are full.
If the number is more than 1, then we know we have some clearing to do.
*/

int Board::rowsChecker(){

	int temp = 0;
	for(int i = 0; i < boardHeight; ++i){
		if(rowFull(i)){
			++temp;
			removeRow(i);
		}
	}
	return temp;
}


/*
This method is in charge of updating the TextDisplay with all pertinent information.
*/

void Board::updateDisplay(int lvl, int scr, int hiscr, char next){
	td->update(lvl, scr, hiscr, next);
}


/*
Overloaded output for operator<<.
*/

ostream &operator<<(ostream &out, const Board &b) {

	out << *(b.td) << endl;
	return out;
}