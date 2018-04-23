#include <stdio.h>
int main(void){
  int a[10];
  int i;
  int sum = 0;
  printf("10個の整数を入力してください\n");
  for(i = 0; i <10; i++){
    printf("%d：",i+1); scanf("%d",&a[i]);
    sum += a[i];
  }
  printf("総和は%d",sum);
}
