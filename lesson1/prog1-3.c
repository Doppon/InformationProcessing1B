#include <stdio.h>
int main(void){
  int i,j;
  printf("i,jに値を入力して下さい。\n");
  printf("i:"); scanf("%d",&i);
  printf("j:"); scanf("%d",&j);
  if(j == 0) {
    printf("われませんよ");
  }
  else {
    printf("%dわる%dは%lf",i,j,(double)i/j);
  }
}
