#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>
#include "redraw.h"

void getMonsterLocation(POSITION *monster){
	srand((unsigned)time(NULL));
	int dx;
	int dy;
		switch (rand()%3) {
	    case 0:
	        dx = -1;	break;
	    case 1:
	        dx = 0;		break;
	    case 2:
	        dx = 1;		break;
	    default:
	    	break;
		}
		switch (rand()%3) {
	    case 0:
	        dy = 1;		break;
	    case 1:
	        dy = 0;		break;
	    case 2:
	        dy = -1;	break;
	    default:
	    	break;
		}

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
}

void redraw(){
	POSITION monster;
	char *ch = "M";
	int key;//これがint型でいいことが大発見なんだがｗ

	initscr();//COLS,LINESが使えるようになる
	noecho();
	cbreak();
	curs_set(0);
	timeout(100);

	start_color();
	init_pair(1, COLOR_RED, COLOR_WHITE);
	bkgd(COLOR_PAIR(1));

	monster.x = COLS/2;
	monster.y = LINES/2;

	while(1){
		//erase();	//もし入れると残像が消える。
	    mvprintw(monster.y,monster.x," ");
		mvprintw(monster.y,monster.x,"%s",ch);
		getMonsterLocation(&monster);
		refresh();
		key = getch();
		if(key == 'q')  break;
		
	}
	endwin();
}









