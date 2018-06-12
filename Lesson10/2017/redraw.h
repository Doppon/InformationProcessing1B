#ifndef REDRAW_H_
#define REDRAW_H_

struct position{
	int x, y;
};
//てかこの２変数のためだけに構造体とかｗ
typedef struct position POSITION;
//参照の仕方だけど確かPOSITION.xとかでいいんだよね？ｗ
void redraw();
void getMonsterLocation(POSITION *monster);

#endif

//これもこれで完成してるっぽいぽい