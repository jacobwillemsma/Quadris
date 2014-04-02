#include "board.h"
using namespace std;

Board::Board() {
	BOARD_WIDTH = 10;
	BOARD_HEIGHT = 18;
	td = new TextDisplay(BOARD_HEIGHT, BOARD_WIDTH);
	theBoard = new Cell *[BOARD_WIDTH];
    for (int i = 0; i < BOARD_WIDTH; i++) // Create the cells.
        this->theBoard[i] = new Cell[this->BOARD_HEIGHT];
	for (int i = 0; i < this->BOARD_WIDTH; i++) {
		for (int j = 0; j < this->BOARD_HEIGHT; j++) {
			theBoard[i][j].init(i, j); // Fill in some of the data.
		}
	}
}

bool Board::isOccupied(int r, int c) {
	return theBoard[r][c].isOccupied();
}

void Board::update(int r, int c, char type) {
	td->notify(r, c, type);
}

ostream &operator<<(ostream &out, const Board &b) {
	if (b.td)
		return out << *(b.td);
	return out;
}