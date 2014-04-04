#include "score.h"


/*
Constructor.
*/

Score::Score() : score(0), hiScore(0){}


/*
The following two methods are used to access and retrieve score nad hiscore 
respectively.
*/

int Score::getScore() {
	return score;
}

int Score::getHiScore() {
	return hiScore;
}


/*
The following method is to reset the score to 0.  Used during a restarted game.
*/

void Score::resetScore() {
	score = 0;
}


/*
The following method is used to add to a prexisting score.  If the score is bigger
than the highscore, we update hiscore as well.
*/

void Score::increaseScore(int x) {
	score += x;
	
	if(score > hiScore){
		hiScore = score;
	}
}