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
	delete current;
	delete next;
}

void Grid::levelUp(){
	// levels up and changes to "rand" source. will not, currently, go above level 3
	if(level == 0){
		level = 1;
		source = "rand";
	}
	else if(level < 3){
		++level;
	}
}

void Grid::levelDown(){ // changes the level down and makes the minimal necessary adjustments
	// if trying to level down from 0, nothing happens, from 1 to 0, the source changes, everything else, just the level variable drop is needed
	if(level == 1){
		level = 0;
		source = "sequence.txt";
	}
	else if(level > 0){ 
		--level;
	}
}

Block Grid::getBlock(string block){
	if(block == "iblock"){
		currentBlockHeight = 1;
		return new IBlock();
	}
	else if(block == "jblock"){
		currentBlockHeight = 2;
		return new JBlock();
	}
	else if(block == "tblock"){
		currentBlockHeight = 2;
		return new TBlock();
	}
	else if(block == "lblock"){
		currentBlockHeight = 2;
		return new LBlock();
	}
	else if(block == "oblock"){
		currentBlockHeight = 2;
		return new OBlock();
	}
	else if(block == "sblock"){
		currentBlockHeight = 2;
		return new SBlock();
	}
	else if(block == "zblock"){
		currentBlockHeight = 2;
		return new ZBlock();
	}
}

Block Grid::getRandBlock(){
	// somehow get a random block....
	
	if(level == 1){
	
	}
	else if(level == 2){
	
	}
	else if(level == 3){
	
	}
}

void Grid::gameStart(){ // should only be called to start a new game, ie board and all relevant variables are cleared
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

Grid::Grid() : board(0), level(0), source("sequence.txt"), currentBlockHeight(0) {
	d = new Display(boardHeight, boardWidth);
	gameStart(0);
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

void Grid::drop(){

}

void Grid::left(){

}

void Grid::right(){

}