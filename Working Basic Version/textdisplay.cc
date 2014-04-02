#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay(int r, int c) {
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

ostream &operator<<(ostream &out, const TextDisplay &td){ // need to do correct positioning for scores and such later
	cout << "----------" << endl;
	// prints the entire Board 
	for(int i = 0; i < 18; ++i){
		for(int j = 0; j < 10; ++j){
			out << td.theDisplay[i][j];
		}
	}
	cout << "----------" << endl;
		
	return out;
}