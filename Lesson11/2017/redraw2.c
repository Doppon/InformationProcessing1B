#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include "redraw2.h"

void initPlayerLocation(POSITION *player){
  mvprintw(player->y,player->x," ");
  player->x=5;
  player->y=5;
  mvprintw(player->y, player->x,"@");
}

void getPlayerLocation(POSITION *player, int key){
  switch(key){
    case KEY_LEFT:
      if(player->x > 0){
        player->x -= 1;
      }
      break;
    case KEY_RIGHT:
      if(player->x < COLS-1){
        player->x += 1;
      }
      break;
    case KEY_UP:
      if(player->y > 0){
        player->y -= 1;
      }
      break;
    case KEY_DOWN:
      if(player->y < LINES-1){
        player->y += 1;
      }
    default:
      break;
  }
}


void getMonsterLocation(POSITION *monster, POSITION *treasure, int *numTreasure){
  int dx;
  int dy;
  switch (rand()%3) {
    case 0:
        dx = -1;  break;
    case 1:
        dx = 0;   break;
    case 2:
        dx = 1;   break;
    default:
        break;
  }
  switch (rand()%3) {
    case 0:
        dy = 1;   break;
    case 1:
        dy = 0;   break;
    case 2:
        dy = -1;  break;
    default:
      break;
  }
  int origX,origY;
  origX = monster->x;
  origY = monster->y;

  int dice;
  dice = rand()%10;

  if(monster->x > 0 && dx < 0){
    monster->x = monster->x + dx;
  }
  if(monster->x < COLS-1 && dx > 0){
    monster->x = monster->x + dx;
  }
  if(monster->y > 0 && dy < 0){
    monster->y = monster->y + dy;
  }
  if(monster->y < LINES-1 && dy > 0){
    monster->y = monster->y + dy;
  }

  if((*numTreasure == 1) && (monster->x == treasure->x) && (monster->y == treasure->y)){
    monster->x = origX;
    monster->y = origY;
  }

  if((dice == 0) && (*numTreasure == 0) && (monster->x != origX)){
    treasure->x = origX;
    treasure->y = origY;
    *numTreasure = 1;
    mvprintw(treasure->y,treasure->x,"T");
  }

  if((dice == 0) && (*numTreasure == 0) && (monster->y != origY)){
    treasure->x = origX;
    treasure->y = origY;
    *numTreasure = 1;
    mvprintw(treasure->y,treasure->x,"T");
  }
}


int getTreasure(POSITION *player,POSITION *treasure,int *numTreasure){
  if((*numTreasure == 1) && ((player->x == treasure->x) && (player->y == treasure->y))){
    mvprintw(treasure->y,treasure->x," ");
    numTreasure = 0;
    return 1;
  }else{
    return 0;
  }
}

int encounter(POSITION *player,POSITION *monster){
  if((player->x == monster->x) && (player->y == monster->y)){
    return 1;
  }else{
    return 0;
  }
}


void initMonsterLocation(POSITION *monster){
  mvprintw(monster->y,monster->x," ");
  int x,y;
  monster->y = LINES/2;
  monster->x = COLS/2;
  mvprintw(monster->y,monster->x,"M");
}

void initTreasureLocation(POSITION *treasure, int *numTreasure){
  mvprintw(treasure->y,treasure->x," ");
  *numTreasure=0;
}

char gameOver(){
  int x, y;
  char *ch = "GAME_OVER";

  getmaxyx(stdscr, LINES, COLS);
  y = LINES/2;
  x = (COLS - strlen(ch))/2;

  mvprintw(y,x,"%s",ch);
  refresh();
  sleep(2);
  return 'q';
}

















