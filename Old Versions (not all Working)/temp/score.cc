#include "score.h"
using namespace std;

Score::Score() {
	this->score = 0;
	this->highScore = 0;
}

int Score::getScore() {
	return this->score;
}

int Score::getHighScore() {
	return this->highScore;
}

void Score::resetScore() {
	this->score = 0;
}

void Score::updateScore() {

}