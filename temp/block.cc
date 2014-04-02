#include "block.h"
#include <iostream>

using namespace std;

bool Block::inRange(){
	if(positions == 0) return false; // shouldn't happen
	
	// if any positions are out of range, returns false
	for(int i = 0; i < 8; ++i){
		if(positions[i] < 0 || positions[i] > 15)
			return false;
	}
	
	return true;
}

int Block::getLevel(){
	return level;
}

bool Block::left(){
	if(positions == 0) return false; // should never happen!!
	
	// moves every x position 1 to the left, returns false if any positions cannot move left
	for(int i = 1; i < 8; i = i + 2){
		--positions[i];
	}
	return inRange();
}

bool Block::right(){
	if(positions == 0) return false; // shouldn't happen
	
	// moves every x position 1 to the left, returns false if any positions cannot move left
	for(int i = 1; i < 8; i = i + 2){
		++positions[i];
	}
	return inRange();
}

bool Block::down(){
	if(positions == 0) return false; // shouldn't happen
	
	// moves every y position 1 down, returns false if this fails
	for(int i = 0; i < 8; i = i + 2){
		++positions[i];
	}
	return inRange();
}


char Block::getType(){
	return type;
}


int * Block::getPositions(){
	return positions;
}

void Block::setPositions(int * pos){
	for(int i = 0; i < 8; ++i){
		positions[i] = pos[i];
	}
}

Block::Block(int lvl, char t) : positions(0), level(lvl), type(t){}
Block::~Block(){}