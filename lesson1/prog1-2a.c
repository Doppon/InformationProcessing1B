#include <stdio.h>
int main(int argc, char *argv[]){
  int sum,one,two;
  printf("引数の数: %d\n", argc);
  for (int i = 0; i < argc; i++)
  {
      printf("%d: %s\n", i, argv[i]);
  }
  one = atoi(argv[1]);
  two = atoi(argv[2]);
  sum = one + two;
  printf("%d",sum);
}
