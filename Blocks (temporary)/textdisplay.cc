#include "textdisplay.h"
#include <iostream>
#include <sstream>

using namespace std;

// functions outlined in .h

TextDisplay::TextDisplay(int r, int c) : rows(r), cols(c){
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

void TextDisplay::notify(int r, int c, char ch){
	theDisplay[r][c] = ch; // changes coordinates of the display
}

void displayUpdate(int lvl, int scr, int hs, char type){
	level = lvl;
	score = scr;
	hiScore = hs;
	nextType = type;	
}

  void displayUpdate(); // updates variables in the display

void TextDisplay::blockPrint(){
	if(nextType == 'I'){
		cout << "IIII";
	}
	else if(nextType == 'J'){
		cout << "J" << endl;
		cout << "JJJ";
	}
	else if(nextType == 'L'){
		cout << "  L" << endl;
		cout << "LLL" << endl;
	}
	else if(nextType == 'O'){
		cout << "OO" << endl;
		cout << "OO" << endl;
	}
	else if(nextType == 'S'){
		cout << " SS" << endl;
		cout << "SS" << endl;
	}
	else if(nextType == 'T'){
		cout << "TTT" << endl;
		cout << " T" << endl;
	}
	else if(nextType == 'Z'){
		cout << "ZZ" << endl;
		cout << " ZZ" << endl;
	}
}


TextDisplay::~TextDisplay(){
	// deletes the display
	for(int i = 0; i < gridSize; ++i){
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
}

ostream &operator<<(ostream &out, const TextDisplay &td){ // need to do correct positioning for scores and such later
	cout << "Level: " << level << endl;
	cout << "Score: " << score << endl;
	cout << "Hiscore: " << hiScore << endl;
	
	cout << "----------" << endl;
	// prints the entire Board 
	for(int i = 0; i < td.rows; ++i){
		for(int j = 0; j < td.cols; ++j){
			out << td.theDisplay[i][j];
		}
	}
	cout << "----------" << endl;
	
	blockPrint();
	
	return out;
}