#include <stdio.h>
int main(void){
  struct _pref{
    char name[50];
    int population;
  };
  typedef struct _pref PREF;
  
  FILE *csv;
  
  int i = 0, j;
  
  csv=fopen("2018_population.csv", "r");
  if(csv==NULL){
    printf("ファイルが開けませんでした。");
    return -1;
  }

  PREF list[50];
  while(fscanf(csv, "%s %d", list[i].name, &list[i].population) != EOF){
    i++;
  }

  PREF a;
  for (i = 0 ; i < 47; i++){
    for(j=i+1; j < 47; j++){
      if(list[i].population > list[j].population){
        a = list[i];
        list[i]=list[j];
        list[j]=a;
      }
    }
  }

  for (i = 0; i < 20; i++){
    printf("%d件目：%s %d\n", i+1, list[i].name, list[i].population);
  }

  fclose(csv);
  return 0;
}
