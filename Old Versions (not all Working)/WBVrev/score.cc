#include "score.h"

Score::Score() : score(0), hiScore(0){}

int Score::getScore() {
	return score;
}

int Score::getHiScore() {
	return hiScore;
}

void Score::resetScore() {
	score = 0;
}

void Score::increaseScore(int x) {
	score += x;
	
	if(score > hiScore){
		hiScore = score;
	}
}