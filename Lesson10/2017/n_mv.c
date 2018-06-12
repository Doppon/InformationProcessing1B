#include <ncurses.h>
#include <string.h>

int main()
{
  char mesg[]="M";
  int row,col;

  initscr();  // 端末制御の開始
  noecho();
  cbreak();
  curs_set(0);//点滅がなくなる
  getmaxyx(stdscr,row,col);

  int i;
  for(i=0;i<=100;i++){
    mvprintw( i,(col-strlen(mesg))/2,"%s",mesg);
    refresh();
  }
  //mvprintw( row-2,0,"rows=%d columns=%d\n",row,col);
  
  getch();  // キー入力 
  endwin(); // 端末制御の終了
  return (0);
}


