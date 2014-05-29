#include "iblock.h"
using namespace std;


/*
Constructor and destructor.
The constructor is in charge of creating the initial positions of a block
on the board.
The destructor deletes the position area or coordinates.
*/

IBlock::IBlock(Board *b, int lvl) {
	level = lvl;
	type = 'I';
	positions = new Coordinate[4];
	
	for (int i = 0; i < 4; ++i) {
		positions[i].setX(i);
		positions[i].setY(3);
	}
	
	// Checks for if the Game is Over, if it is, it set gameOver to true.
	gameOver = false;
	for (int i = 0; i < 4; ++i) {
		if (b->isOccupied(positions[i].getY(), positions[i].getX()))
			gameOver = true;
	}
	
	for(int i = 0; i < 4; ++i){
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

IBlock::~IBlock(){
	delete [] positions;
}


/*
The rotate functions rotate the block based on it's current configuration into it's
"next" rotational configuration. They also subsequently check if the rotate is permitted.
*/

void IBlock::clockwise(Board *b){ // r and c not needed here
	bool temp = true;
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), ' ');
	}
	
	if(positions[0].getY() == positions[1].getY()){
		positions[0].addY(-3);
		// positions[0].addX() does not change
		positions[1].addY(-2);
		positions[1].addX(-1);
		positions[2].addY(-1);
		positions[2].addX(-2);
		// positions[3] does not change
		positions[3].addX(-3);
	}
	else if(positions[0].getX() == positions[1].getX()){
		if(positions[0].getX() < 7){
			positions[0].addY(3);
			// positions[0].addY() does not change
			positions[1].addY(2);
			positions[1].addX(1);
			positions[2].addY(1);
			positions[2].addX(2);
			// positions[3].addY() does not change
			positions[3].addX(3);
		}
	}
	
	for (int i = 0; i < 4; i++) {
		if (positions[i].getY() > 17 || positions[i].getX() > 9 || positions[i].getX() < 0 || b->isOccupied(positions[i].getY(), positions[i].getX()))
			temp = false;
	}
	
	
	if(!temp){
		if(positions[0].getY() == positions[1].getY()){
			positions[0].addY(-3);
			// positions[0].addX() does not change
			positions[1].addY(-2);
			positions[1].addX(-1);
			positions[2].addY(-1);
			positions[2].addX(-2);
			// positions[3] does not change
			positions[3].addX(-3);
		}
		else if(positions[0].getX() == positions[1].getX()){
			if(positions[0].getX() < 7){
				positions[0].addY(3);
				// positions[0].addY() does not change
				positions[1].addY(2);
				positions[1].addX(1);
				positions[2].addY(1);
				positions[2].addX(2);
				// positions[3].addY() does not change
				positions[3].addX(3);
			}
		}
	}
	
	// Update the display
	for (int i = 0; i < 4; i++) {
		b->update(positions[i].getY(), positions[i].getX(), type);
	}
}

void IBlock::counterclockwise(Board *b){ // r and c not needed here
	return clockwise(b);
}