#include "cell.h"
#include "display.h"
//#include "xwindow.h"
#include <string>

using namespace std;

void Grid::clearBoard(){
		// clears the grid by deleting all Cells
	for(int i = 0; i < boardHeight; ++i){
		delete [] board[i];
	}
}

void Grid::gameStart(string source){ // should only be called to start a new game, ie board and all relevant variables are cleared
	/*
	current = getBlock(); //?
	next = getBlock(); //?
	*/
	
	if(source == "rand"){
		current = getRandBlock();
		next = getRandBlock();
	}
	else{
		current = getBlock(source);
		next = getBlock(source);
	}
	
	board = new Cell*[boardHeight];
	
	// fills the new Grid with cells
	for(int i = 0; i < boardHeight; ++i){
		board[i] = new Cell[boardWidth];
	}
	
	// sets the coordinates for the cells
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			theGrid[i][j].init(i,j);
		}
	}
}


Cell Grid::getLocation(int r, int c){
	return board[r][c];
}

bool Grid::rowFull(int n){
	for(int i = 0; i < boardWidth; ++i){
		if(!isFull(n, i)) return false;
	}
	return true;
}

void Grid::lineCheck(){ // checks to see if a row is full
	for(int i = 0; i < boardHeight; ++i){
		if(rowFull(i)) removeRow(i);
	}
}

bool Grid::isFull(int r, int c){ // checks if a Cell is occupied
	if(theboard[r][c].getSymbol() != ' ') return true;
	else return false;
}

void Grid::removeRow(int r){
	for(int i = r; r > 1; --i){
		for(int j = 0; j < boardWidth; ++j){
			board[i][j].setSymbol(board[i-1][j].getSymbol());
		}
	}
	clearRow(0);
}

void Grid::clearRow(int r){
	for(int i = 0; i < boardWidth; ++i){
		board[r][i].setSymbol(' ');
	}
}

bool Grid::gameOver(){
	
}

bool canPlay(){
	//...?
}

void restartGame(){
	clearBoard();
	gameStart();
}

Grid::Grid() : board(0) {
	d = new Display(boardHeight, boardWidth);
}

Grid::~Grid(){
	// deletes the entire board of cells and the Display
	for(int i = 0; i < boardHeight; ++i){
		delete [] board[i];
	}
	delete d;
}

void Grid::down(){
	
}


	
	void down();
	void drop();
	void left();
	void right();