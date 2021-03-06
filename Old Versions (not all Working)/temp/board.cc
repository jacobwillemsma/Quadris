#include "board.h"
#include <string>

using namespace std;

void Board::clearBoard(){
	// clears the Board by deleting all Cells
	for(int i = 0; i < BOARD_HEIGHT; ++i){
		delete [] theBoard[i];
	}
	delete current;
	delete next;
	delete score;
}

void Board::clearRow(int r){
	for(int i = 0; i < BOARD_WIDTH; ++i){
		if(theBoard[r][i].clearCell())
			//update the score somehow...  score.update()?
			int filler = 0;
	}
}

void Board::gameStart(int lvl){
	// should only be called to start a new game, ie board and all relevant variables are cleared
	
	theBoard = new Cell*[BOARD_HEIGHT];
	currentPosition = new int [8];
	nextPosition = new int [8];
	
	// LEVEL STUFF
	level = lvl;
	
	
	// fills the new Board with cells
	for(int i = 0; i < BOARD_HEIGHT; ++i){
		theBoard[i] = new Cell[BOARD_WIDTH];
	}
	
	// sets the coordinates for the cells
	for(int i = 0; i < BOARD_HEIGHT; ++i){
		for(int j = 0; j < BOARD_WIDTH; ++j){
			theBoard[i][j].init(i,j);
		}
	}
	
	// nextBlock nb = new NextBlock?
	
	// need a next block somehow, the implementation of that is unclear
	/*if(source == "rand"){
		current = getRandBlock();
		next = getRandBlock();
	}
	else{
		current = getBlock(source);
		next = getBlock(source);
	}*/
	
	updateDisplay();
}

void Board::rowsChecker(){
	for(int i = 0; i < BOARD_HEIGHT; ++i){
		if(rowFull(i))
			removeRow(i);
	}
}

bool Board::rowFull(int r){
	for(int i = 0; i < BOARD_WIDTH; ++i){
		if(!isOccupied(r, i)) return false;
	}
	return true;
}

void Board::removeRow(int r){
	for(int i = r; r > 0; --i){
		for(int j = 0; j < BOARD_WIDTH; ++j){
			theBoard[i][j] = theBoard[i-1][j]; // NEED AN ASSIGNMENT OPERATOR FOR CELL???
		}
	}
	clearRow(0);
}

bool Board::isOccupied(int r, int c){
	return theBoard[r][c].isOccupied();
}


void Board::revert(int move){ // reverts the move
	
}

bool Board::gameOver(){
	// might be handled differently.. will wait on this
	return false;
}

// updates the display
void Board::updateDisplay(){
	for(int i = 0; i < BOARD_HEIGHT; ++i){
		for(int j = 0; j < BOARD_WIDTH; ++j){
			theBoard[i][j].notifyDisplay(*td);
		}
	}
	td->displayUpdate(level, score->getScore(), score->getHighScore(), next->getType());
}


Board::Board() : theBoard(0), current(0), next(0), level(0), currentPosition(0), nextPosition(0), currentRow(0), currentCol(0){
	td = new TextDisplay(BOARD_HEIGHT, BOARD_WIDTH);
	gameStart(0);
	score = new Score();
}

Board::~Board(){
	// deletes the entire board of cells and the Display
	for(int i = 0; i < BOARD_HEIGHT; ++i){
		delete [] theBoard[i];
	}
	delete td;
	// delete xw;
}



bool Board::down(){
	++currentRow;
	bool valid = current->down();
	nextPosition = current->getPositions();
	
	for(int i = 0; i < BLOCK_SIZE*2; i = i + 2){
		if(theBoard[nextPosition[i]][nextPosition[i+1]].isOccupied()){
			valid = false;
		}
	}
	
	if(valid){
		for(int i = 0; i < BLOCK_SIZE*2; ++i){
			currentPosition[i] = nextPosition[i];
		}
		updateDisplay();
	}
	else{
		//REVERT THE BLOCK SOMEHOW
	}
	
	return valid;
}

bool Board::left(){
	--currentCol;
	bool valid = current->left();
	nextPosition = current->getPositions();
	
	for(int i = 0; i < BLOCK_SIZE*2; i = i + 2){
		if(theBoard[nextPosition[i]][nextPosition[i+1]].isOccupied()){
			valid = false;
		}
	}
	
	if(valid){
		for(int i = 0; i < BLOCK_SIZE*2; ++i){
			currentPosition[i] = nextPosition[i];
		}
		updateDisplay();
	}
	else{
		//REVERT THE BLOCK SOMEHOW
	}
	
	return valid;
}

bool Board::right(){
	++currentCol;
	bool valid = current->right();
	nextPosition = current->getPositions();
	
	for(int i = 0; i < BLOCK_SIZE*2; i = i + 2){
		if(theBoard[nextPosition[i]][nextPosition[i+1]].isOccupied()){
			valid = false;
		}
	}
	
	if(valid){
		for(int i = 0; i < BLOCK_SIZE*2; ++i){
			currentPosition[i] = nextPosition[i];
		}
		updateDisplay();
	}
	else{
		//REVERT THE BLOCK SOMEHOW
	}
	
	return valid;
}

bool Board::clockwise(){
	bool valid = current->clockwise(currentRow, currentCol);
	nextPosition = current->getPositions();
	
	for(int i = 0; i < BLOCK_SIZE*2; i = i + 2){
		if(theBoard[nextPosition[i]][nextPosition[i+1]].isOccupied()){
			valid = false;
		}
	}
	
	if(valid){
		for(int i = 0; i < BLOCK_SIZE*2; ++i){
			currentPosition[i] = nextPosition[i];
		}
		updateDisplay();
	}
	else{
		//REVERT THE BLOCK SOMEHOW
	}
	
	return valid;
}

bool Board::counterclockwise(){
	bool valid = current->counterclockwise(currentRow, currentCol);
	nextPosition = current->getPositions();
	
	for(int i = 0; i < BLOCK_SIZE*2; i = i + 2){
		if(theBoard[nextPosition[i]][nextPosition[i+1]].isOccupied()){
			valid = false;
		}
	}
	
	if(valid){
		for(int i = 0; i < BLOCK_SIZE*2; ++i){
			currentPosition[i] = nextPosition[i];
		}
		updateDisplay();
	}
	else{
		//REVERT THE BLOCK SOMEHOW
	}
	
	return valid;
}


bool Board::drop(){ // drops the current block and makes the next block the current block, as well as generating a new current block and making Cells neighbours
	while(down()){} // loops down as far as possible
	
	// there must be a better way to do this!!!!!
	nextPosition = current->getPositions();
	Cell temp1 = theBoard[nextPosition[0]][nextPosition[1]];
	Cell temp2 = theBoard[nextPosition[2]][nextPosition[3]];
	Cell temp3 = theBoard[nextPosition[4]][nextPosition[5]];
	Cell temp4 = theBoard[nextPosition[6]][nextPosition[7]];
	
	temp1.addNeighbour(&temp2);
	temp1.addNeighbour(&temp3);
	temp1.addNeighbour(&temp4);
	
	temp2.addNeighbour(&temp1);
	temp2.addNeighbour(&temp3);
	temp2.addNeighbour(&temp4);
	
	temp3.addNeighbour(&temp1);
	temp3.addNeighbour(&temp2);
	temp3.addNeighbour(&temp4);
	
	temp4.addNeighbour(&temp1);
	temp4.addNeighbour(&temp2);
	temp4.addNeighbour(&temp3);
	
	
	
	current = next;
	currentPosition = next->getPositions();
	for(int i = 0; i < BLOCK_SIZE*2; i = i + 2){
		if(theBoard[nextPosition[i]][nextPosition[i+1]].isOccupied()){
			return false; // when this is false, the game should be OVER
		}
	}
	
	
	
	// next = newBlock(); ??
	
	//temp
	return true;
}



void Board::levelUp(){
	++level;
}

void Board::levelDown(){
	if(level > 0) --level;
}


Cell Board::getCell(int r, int c){
	return theBoard[r][c];
}

void Board::restartGame(){
	clearBoard();
	gameStart(level);
}

ostream &operator<<(ostream &out, Board b){
	// do the printings
	return out;
}
