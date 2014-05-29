#include "textdisplay.h"
using namespace std;


/*
Constructor and destructors.
*/

TextDisplay::TextDisplay(int r, int c) : rows(r), cols(c), level(0), score(0), hiScore(0) {

	// Creates the display.
	theDisplay = new char*[r];
	for(int i = 0; i < r; ++i){
		theDisplay[i] = new char[c];
	}

	// Makes the display 'empty'
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			theDisplay[i][j] = ' ';
		}
	}
}

TextDisplay::~TextDisplay() {
	
	// Deletes the 2X2 array that is the Display.
	for(int i = 0; i < 18; ++i){
		delete [] theDisplay[i];
	}
	delete [] theDisplay;
}


/*
The following two methods are used to update the display.  The first to update the actual Display
to have the charactor ch now appear and the second to update the whole TextDisplay class.  These
are used when moving blocks in any way and to update the display after a movement respectively.
*/

void TextDisplay::notify(int r, int c, char ch){
	theDisplay[r][c] = ch;
}

void TextDisplay::update(int lvl, int scr, int hiscr, char type){
	level = lvl;
	score = scr;
	hiScore = hiscr;
	next = type;
}

/*
Overload of the operator<< for TextDisplays.  Shows the score, highscore, board and next block.
*/

ostream &operator<<(ostream &out, const TextDisplay &td){ // need to do correct positioning for scores and such later
	cout << "Level: " << td.level << endl;
	cout << "Score: " << td.score << endl;
	cout << "Hiscore: " << td.hiScore << endl;
	
	cout << "____________" << endl;
	// prints the entire Board 
	for(int i = 0; i < td.rows; ++i){
		cout << "|";
		for(int j = 0; j < td.cols; ++j){
			out << td.theDisplay[i][j];
		}
		cout << "|" << endl;
	}
	cout << "¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
	cout << "Next:" << endl;
	
	char next = td.next;
	
	if(next == 'I'){
		cout << "IIII" << endl;
	}
	else if(next == 'J'){
		cout << "J" << endl;
		cout << "JJJ";
	}
	else if(next == 'L'){
		cout << "  L" << endl;
		cout << "LLL";
	}
	else if(next == 'O'){
		cout << "OO" << endl;
		cout << "OO";
	}
	else if(next == 'S'){
		cout << " SS" << endl;
		cout << "SS";
	}
	else if(next == 'T'){
		cout << "TTT" << endl;
		cout << " T";
	}
	else if(next == 'Z'){
		cout << "ZZ" << endl;
		cout << " ZZ";
	}
	else if(next == 'A') {

		// If on the last block in the sequence file.
		cout << "You are out of input in your file!" << endl;
		cout << "Move on to level 1, 2 or 3 to keep your current game!";
	}
	cout << endl;
	
	return out;
}