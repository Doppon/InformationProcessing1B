#include <ncurses.h>
#include <string.h>
#include <unistd.h>
int main()
{
  int x, y, w, h;
  char *ch = "M";
  int key;

  initscr();  // 端末制御の開始
  noecho();
  cbreak();
  //今回の追加はtimeoutかな
  timeout(0);

  start_color();  // カラーの設定
  init_pair(1, COLOR_RED, COLOR_WHITE);  // 色番号１を赤文字／青地とする
  bkgd(COLOR_PAIR(1));      // 色１をデフォルト色とする

  getmaxyx(stdscr, h, w);
  y = h/2;
  x = (w - strlen(ch))/2;

  while(1){
    erase();
    move(y,x);
    addstr(ch);
    refresh();

    key = getch();
    if(key == 'q')  break;

    y++;
    if(y >= h) y=0;
    
    usleep(10000);
  }

  endwin(); // 端末制御の終了
  return (0);
}

