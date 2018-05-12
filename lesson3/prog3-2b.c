#include <stdio.h>
int main(void){
  FILE *csv;
  int i, j;
  struct _pref{
    char name[50];
    int population;
  };
  typedef struct _pref PREF;
  PREF scan_list[50];
  PREF sort_list;

  csv = fopen("2018_population.csv", "r");
  if(csv == NULL){
    printf("ファイルが開けませんでした。");
    return -1;
  }

  while(fscanf(csv, "%s %d", scan_list[i].name, &scan_list[i].population) != EOF){
    i++;
  }

  for (i = 0 ; i < 47; i++){
    for(j = i+1; j < 47; j++){
      if(scan_list[i].population > scan_list[j].population){
        sort_list = scan_list[i];
        scan_list[i] = scan_list[j];
        scan_list[j] = sort_list;
      }
    }
  }

  for (i = 0; i < 20; i++){
    printf("%d件目：%s %d\n", i+1, scan_list[i].name, scan_list[i].population);
  }

  fclose(csv);
  return 0;
}
