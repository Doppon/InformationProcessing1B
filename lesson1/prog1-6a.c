#include <stdio.h>
int main(int argc, char *argv[]){
  int num;
  num = atoi(argv[1]);
  int a[num];
  int i;
  int sum = 0;
  for(i = 0; i <num; i++){
    printf("%d：",i+1); scanf("%d",&a[i]);
    sum += a[i];
  }
  printf("総和は%d",sum);
}
