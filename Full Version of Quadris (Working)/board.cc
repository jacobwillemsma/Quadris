#include "board.h"
using namespace std;

Board::Board(){
	BOARD_WIDTH = 10;
	BOARD_HEIGHT = 18;
	td = new TextDisplay(BOARD_HEIGHT, BOARD_WIDTH);
	theBoard = new Cell *[BOARD_HEIGHT];
    for (int i = 0; i < BOARD_HEIGHT; i++) // Create the cells.
        this->theBoard[i] = new Cell[this->BOARD_WIDTH];
	for (int i = 0; i < this->BOARD_HEIGHT; i++) {
		for (int j = 0; j < this->BOARD_WIDTH; j++) {
			theBoard[i][j].init(i, j); // Fill in some of the data.
		}
	}
}

Board::~Board(){
	for(int i = 0; i < BOARD_HEIGHT; ++i){
		delete [] theBoard[i];
	}
	delete [] theBoard;
	delete td;
}

void Board::clearBoard(){
	// clears the Board by deleting all Cells
	for(int i = 0; i < BOARD_HEIGHT; ++i){
		for(int j = 0; j < BOARD_WIDTH; ++j){
			theBoard[i][j].setSymbol(' ');
			td->notify(i, j, ' ');
		}
	}
}

bool Board::isOccupied(int r, int c) {
	return theBoard[r][c].isOccupied();
}

void Board::update(int r, int c, char type) {
	theBoard[r][c].setSymbol(type);
	td->notify(r, c, type);
}

int Board::rowsChecker(){
	int temp = 0;
	for(int i = 0; i < BOARD_HEIGHT; ++i){
		if(rowFull(i)){
			++temp;
			removeRow(i);
		}
	}
	return temp;
}

bool Board::rowFull(int r){
	for(int i = 0; i < BOARD_WIDTH; ++i){
		if(!isOccupied(r, i)) return false;
	}
	return true;
}

void Board::removeRow(int r){
	for(int i = r; i > 1; --i){
		for(int j = 0; j < BOARD_WIDTH; ++j){
			theBoard[i][j].setSymbol(theBoard[i-1][j].getSymbol());
			td->notify(i, j, theBoard[i-1][j].getSymbol());
		}
	}
}


void Board::updateDisplay(int lvl, int scr, int hiscr, char next){
	td->update(lvl, scr, hiscr, next);
}

ostream &operator<<(ostream &out, const Board &b) {
	out << *(b.td) << endl;
	return out;
}