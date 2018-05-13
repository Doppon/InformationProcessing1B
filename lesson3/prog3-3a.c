#include <stdio.h>
int main(int argc, char *argv[]){
  FILE *origin_file;
  FILE *copy_file;
  char line[1000];
  int i = 1;

  origin_file = fopen(argv[1], "r");
  if(origin_file == NULL){
    printf("ファイルが開けませんでした。\n");
    return -1;
  }

  copy_file = fopen(argv[2], "w");
  
  while((fgets(line, sizeof(line), origin_file)) != NULL){
    fprintf(copy_file, "%d:%s", i,line);
    i++;
  }
  printf("[コピー完了しました]\n");
  printf("----------------------------------------------------------\n");
  printf("| コピー元ファイル[%s] -> コピー先ファイル[%s] |\n", argv[1], argv[2]);
  printf("----------------------------------------------------------\n");

  fclose(origin_file);
  fclose(copy_file);
  return 0;
}
