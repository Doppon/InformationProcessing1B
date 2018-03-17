#include <stdio.h>
int main(void){
  int i,j;
  printf("i,jに値を入力して下さい。\n");
  printf("i:"); scanf("%d",&i);
  printf("j:"); scanf("%d",&j);
  printf("%dわる%dは%lf",i,j,(double)i/j);
}
