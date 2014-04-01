#ifndef __SCORE_H__
#define __SCORE_H__
#include <iostream>
#include <string>

class Score {
	int score;
	int highScore;
	Score();
public:
	int getScore();
	int getHighScore();
	void resetScore();
	void updateScore();
}