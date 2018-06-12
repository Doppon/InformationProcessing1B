#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
typedef struct{
  int x;
  int y;
} POSITION;

void getMonsterLocation(POSITION *monster){
  srand((unsigned)time(NULL));
  int dx,dy;
  int i;
  while(i==1){
    switch (rand()%3) {
      case 0:
          dx = -1;  break;
      case 1:
          dx = 0;   break;
      case 2:
          dx = 1;   break;
    }

    switch (rand()%3) {
      case 0:
          dy = 1;   break;
      case 1:
          dy = 0;   break;
      case 2:
          dy = -1;  break;      
    }
    i++;
  }
  monster->x = dx;
  monster->y = dy;
}

int main(void){
  POSITION monster;

  getMonsterLocation(&monster);

  printf("%d\n",monster.x);
  printf("%d\n",monster.y);

  return 0;
}

