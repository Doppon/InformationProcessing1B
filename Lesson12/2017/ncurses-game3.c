#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include "redraw2.h"
#include "highscore.h"

int main(int argc, char** argv){
  /* declaration of variables */
  POSITION *player=(POSITION *)malloc(sizeof(POSITION));
  POSITION *monster=(POSITION *)malloc(sizeof(POSITION));
  POSITION *treasure=(POSITION *)malloc(sizeof(POSITION));
  int cnt=0, ch, i, stage=0, score=0, numTreasure, clear=0;
  /* initialization of rand function */
  srand((unsigned)time(NULL));
  /* initialization of ncurses */
  initscr();//You can use COLS and LINES
  noecho();
  cbreak();
  curs_set(0);
  keypad(stdscr, true);//KEY_SERIES
  wtimeout(stdscr, 500);

  /* Copy Protection */
  start_color();
  init_pair(1, COLOR_RED, COLOR_WHITE);
  bkgd(COLOR_PAIR(1));

  /* initialization of variables */
  player->x=5;
  player->y=5;
  monster->x=70/2;
  monster->y=30/2;

  //Maybe...This means is The treasure is hide.
  treasure->x=-1;
  treasure->y=-1;
  numTreasure=0;
  /* First, let’s read key. */
  ch=getch();

  /* Add the var */
  int highscore = 0;


  /*Make the wall*/
  int height, width;
  for(height = 0; height != 30; height++){
    mvprintw(height,70,"|");
  }
  for(width = 0; width != 70; width++){
    mvprintw(30,width,"-");
  }


  while(ch!='q'){
    /* Add the highscore System*/
    highscore = getHighScore(highscore,score);
    highScoreDisp(highscore);
    

    mvprintw(1,2,"stage : %d", (stage+1));
    mvprintw(2,2,"score : %d", score);
    mvprintw(3,2,"count : %3d", MAX_COUNT-cnt);//Player's life point.
    cnt++;
    /* move monster */
    mvprintw(monster->y,monster->x," ");
    getMonsterLocation(monster, treasure, &numTreasure);
    mvprintw(monster->y,monster->x,"M");
    /* move player */
    mvprintw(player->y,player->x," ");
    getPlayerLocation(player, ch);
    mvprintw(player->y, player->x,"@");
    refresh();
    /* judgement */
    clear+=getTreasure(player,treasure, &numTreasure);  
    if(cnt==MAX_COUNT){
      /* could not get treasures */
      ch=gameOver();
    }else if(encounter(player,monster)){
      /* caught by monster */
      ch=gameOver();
    }else if(clear==stage+1){
      /* stage clear */
      mvprintw(4,2,"Gotcha!");
      refresh();
      sleep(2);
      mvprintw(4,2,"       ");
      stage++;
      score+=MAX_COUNT-cnt;
      cnt=0;
      clear=0;
      initPlayerLocation(player);
      initMonsterLocation(monster);
      initTreasureLocation(treasure, &numTreasure);
    }else{
      ch=getch();
    }
  }
  /* Add highscore System */
  
  
  saveHighScore(getHighScore(loadHighScore(),score));
 


  endwin();
  return 0;
}








