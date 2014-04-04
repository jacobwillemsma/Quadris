#ifndef __SCORE_H__
#define __SCORE_H__

class Score {
	int score;
	int hiScore;
  public:
	Score();
	int getScore();
	int getHiScore();
	void resetScore();
	void increaseScore(int x);
};

#endif