#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "redraw2.h"

int getHighScore(int highScore,int score){
  if(score >= highScore){
    return score;
  }else{
    return highScore;
  }
}

int loadHighScore(){
  FILE *fp;
  int x;
  fp=fopen("highscore.txt","r");
  //fp == NULLとして条件分岐させる。
  if(fp == NULL){
    printf("There are no more file.\n");
    return 0;
  }
  fscanf(fp,"%d",&x);
  return x;
  
  fclose(fp);
}

void saveHighScore(int score){
  FILE *fp;
  fp=fopen("highscore.txt","w");
  if(fp == NULL){
    printf("There are no more file.\n");
  }
  fprintf(fp,"%d",score);
  fclose(fp);
}

void highScoreDisp(int highScore){
  int x, y;
  y = 1;
  x = 70/2-5;
  mvprintw(y,x,"HI SCORE:%3d",highScore);
}


