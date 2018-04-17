#include <stdio.h>
int main(void){
  int i,count_i,count_j;
  printf("iの値を入力して下さい。\n");
  printf("i:"); scanf("%d",&i);
  if(i <= 0){
    printf("正の数を入力してね");
  }

  for(count_i = 1; count_i <= i; count_i++){
    for(count_j = 1; count_j <= count_i; count_j++){
      printf("#"); 
    }
    printf("\n");
  }

  for(count_i = 1; count_i <= i; count_i++){
    for(count_j = i; count_j >= count_i; count_j--){
      printf("#"); 
    }
    printf("\n");
  }

}

