#include <ncurses.h>
#include <string.h>
#include <stdio.h>



char putChar()
{
  int x, y, w, h;
  char *ch = "GAME_OVER";

  getmaxyx(stdscr, LINES, COLS);
  y = LINES/2;
  x = (COLS - strlen(ch))/2;

  refresh();
  mvprintw(y,x,"%s",ch);
  sleep(2);
  
  return 'q';
}

int main()
{
  initscr();  // 端末制御の開始

  int key;
  
  start_color();  // カラーの設定
  init_pair(1, COLOR_RED, COLOR_WHITE);  // 色番号１を赤文字／青地とする
  bkgd(COLOR_PAIR(1));      // 色１をデフォルト色とする

  putChar();

  getch();
  endwin(); // 端末制御の終了
  return (0);
}

