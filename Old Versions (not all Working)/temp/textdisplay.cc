#include "textdisplay.h"
#include <iostream>
#include <sstream>

using namespace std;

// functions outlined in .h

void TextDisplay::notify(int r, int c, char ch){
	theDisplay[r][c] = ch; // changes coordinates of the display
}

void TextDisplay::displayUpdate(int lvl, int scr, int hs, char type){
	level = lvl;
	score = scr;
	hiScore = hs;
	nextType = type;	
}

TextDisplay::TextDisplay(int r, int c) : rows(r), cols(c), level(0), score(0), hiScore(0){
	// creates a new array of chars
	theDisplay = new char*[r];
	
	for(int i = 0; i < r; ++i){
		theDisplay[i] = new char[c];
	}
	
	// makes the display 'empty'
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			theDisplay[i][j] = ' ';
		}
	}
}

TextDisplay::~TextDisplay(){
	// deletes the display
	for(int i = 0; i < rows; ++i){ // should probably change from literal
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
}

// prints each type of block
void blockPrint(char type){
	if(type == 'I'){
		cout << "IIII";
	}
	else if(type == 'J'){
		cout << "J" << endl;
		cout << "JJJ";
	}
	else if(type == 'L'){
		cout << "  L" << endl;
		cout << "LLL" << endl;
	}
	else if(type == 'O'){
		cout << "OO" << endl;
		cout << "OO" << endl;
	}
	else if(type == 'S'){
		cout << " SS" << endl;
		cout << "SS" << endl;
	}
	else if(type == 'T'){
		cout << "TTT" << endl;
		cout << " T" << endl;
	}
	else if(type == 'Z'){
		cout << "ZZ" << endl;
		cout << " ZZ" << endl;
	}
}

ostream &operator<<(ostream &out, const TextDisplay &td){ // need to do correct positioning for scores and such later
	cout << "Level: " << td.level << endl;
	cout << "Score: " << td.score << endl;
	cout << "Hiscore: " << td.hiScore << endl;
	
	cout << "----------" << endl;
	// prints the entire Board 
	for(int i = 0; i < td.rows; ++i){
		for(int j = 0; j < td.cols; ++j){
			out << td.theDisplay[i][j];
		}
	}
	cout << "----------" << endl;
	cout << "Next:" << endl;
	
	blockPrint(td.nextType);
	
	return out;
}