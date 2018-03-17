#include <stdio.h>
int main(void){
  int i,j,count_i,count_j;
  printf("i,jに値を入力して下さい。\n");
  printf("(iには行数,jには列数を指定します。)\n");
  printf("i(行数):"); scanf("%d",&i);
  printf("j(列数):"); scanf("%d",&j);
  for(count_i = 1; count_i <= i; count_i++){
    for(count_j = 1; count_j <= j; count_j++){
      printf("#"); 
    }
    printf("\n");
  }
}
