#include <stdio.h>
int main(void){
  struct _pref{
    char name[50];
    int population;
  };
  typedef struct _pref PREF;
  FILE *fp;
  int sum = 0;
  int sum2 = 0;
  int i = 0;
  double ave,bunsan;

  fp=fopen("2018_population.csv", "r");
  if(fp==NULL){
    printf("ファイルが開けませんでした。");
    return -1;
	}

  PREF list[50];
  while(fscanf(fp, "%s%d", list[i].name, &list[i].population)!=EOF){
    sum=sum+list[i].population;
    i++;
  }

  ave = sum/47.0;

  for (i = 0 ; i < 47; i ++){
    sum2 = sum2+(list[i].population-ave)*(list[i].population-ave);
  }
	
  bunsan = sum2/47.0;
  printf("平均:%f, 分散:%f\n", ave, bunsan);
  fclose(fp);
	return 0;
}
