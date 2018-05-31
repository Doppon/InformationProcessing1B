#include <stdio.h>
  int main(void){
	FILE *csv;

	int all_population = 0;
	int sum = 0;
  int i;
  double mean, variance;

  struct _pref{
    char name[50];
    int population;
  };
  typedef struct _pref PREF;

	// 分散の定義
	//
	//  1   n            2
	// ---  Σ [ xi  - μ ]
	//  n  i=1

  csv = fopen("2018_population.csv", "r");
  if(csv == NULL){
    printf("ファイルが開けませんでした。");
    return -1;
  }

  PREF list[50];
  while(fscanf(csv, "%s %d", list[i].name, &list[i].population) !=　EOF){
    all_population += list[i].population;
    i++;
  }

  mean = all_population / 47.0;

  for (i = 0 ; i < 47; i ++){
    sum += (list[i].population - mean) * (list[i].population - mean);
  }

  variance = sum / 47.0;
  printf("平均:%f, 分散:%f\n", mean, variance);
  fclose(csv);
  return 0;
}
