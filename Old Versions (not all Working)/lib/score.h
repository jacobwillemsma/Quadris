#ifndef __SCORE_H__
#define __SCORE_H__


const int maxNeighbours = 3;

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

#endif