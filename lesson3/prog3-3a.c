#include <stdio.h>
int main(int argc, char *argv[]){
  FILE *fp;
  char line[1000];
  int i = 1;

  fp = fopen(argv[1], "r");
  if(fp == NULL){
    printf("ファイルが開けませんでした。\n");
    return -1;
  }

  printf("コピー元ファイル：%s, コピー先ファイル：%s", argv[1], argv[2]);

  fclose(fp);
  return 0;
}
