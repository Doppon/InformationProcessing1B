#include <ncurses.h>
#include <string.h>

int main()
{
  int x, y;
  char *ch = "M";
  int key;//これがint型でいいことが大発見なんだがｗ

  initscr();
  curs_set(0);
  noecho();
  cbreak();
  start_color();  // カラーの設定
  init_pair(1, COLOR_RED, COLOR_WHITE);  // 色番号１を赤文字／青地とする
  bkgd(COLOR_PAIR(1));      // 色１をデフォルト色とする

  getmaxyx(stdscr, LINES, COLS);
  x = (COLS - strlen(ch))/2;
  y = LINES/2;

  while(1){
    erase();
    //move(y,x); addstr(ch);
    mvprintw( y,x,"%s",ch);
    refresh();

    key = getch();
    if(key == 'q')  break;
    //getMonsterLocationを使っていく場面!!
    y++;
    if(y >= LINES) y=0; 
  }
  endwin(); // 端末制御の終了
  return (0);
}

