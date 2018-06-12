#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_
#include "redraw2.h"
int getHighScore(int highScore, int score);
int loadHighScore();
void saveHighScore(int score);
void highScoreDisp(int highScore);
#endif /* HIGHSCORE_H_ */

