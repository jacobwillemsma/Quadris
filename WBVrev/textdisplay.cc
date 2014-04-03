#include "textdisplay.h"
using namespace std;

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

void TextDisplay::notify(int r, int c, char ch){
	theDisplay[r][c] = ch; // changes coordinates of the display
}

TextDisplay::~TextDisplay(){
	// deletes the display
	for(int i = 0; i < 18; ++i){
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
}

void TextDisplay::update(int lvl, int scr, int hiscr, char type){
	level = lvl;
	score = scr;
	hiScore = hiscr;
	next = type;
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
		cout << endl;
	}
	cout << "----------" << endl;
	cout << "Next:" << endl;
	
	char next = td.next;
	
	if(next == 'I'){
		cout << "IIII";
	}
	else if(next == 'J'){
		cout << "J" << endl;
		cout << "JJJ";
	}
	else if(next == 'L'){
		cout << "  L" << endl;
		cout << "LLL" << endl;
	}
	else if(next == 'O'){
		cout << "OO" << endl;
		cout << "OO" << endl;
	}
	else if(next == 'S'){
		cout << " SS" << endl;
		cout << "SS" << endl;
	}
	else if(next == 'T'){
		cout << "TTT" << endl;
		cout << " T" << endl;
	}
	else if(next == 'Z'){
		cout << "ZZ" << endl;
		cout << " ZZ" << endl;
	}
	
	return out;
}