#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "typing.h"

int dataReader(DATA *dataArray, int *n)
{
  FILE *fp;
  int i = 0;
  fp = fopen("typing.txt", "r");
  if (fp == NULL) {
    puts("invalid quiz file");
    return -1;
  }
  while (fscanf(fp, " %[^,],%d", dataArray[i].string, &dataArray[i].score) != EOF) {
    i++;
  }
  *n = i;
  fclose(fp);
  return 0;
}

int typing(DATA *dataArray, int n)
{
  int i;
  int p=0;
  double t=20, diff=0;
  char answer[10];
  time_t starttime, endtime;
  // 精度の高い乱数を生成するため追記
	srand(time(NULL));  

  while (t >= 0) {
    i = rand() % n;

    starttime = time(NULL);

    printf("\n%s\n", dataArray[i].string);
    scanf("%s", answer);

    endtime = time(NULL);
    diff = difftime(endtime, starttime);
    
    if (strcmp(dataArray[i].string, answer) == 0) {
      t = t + dataArray[i].score - diff;
      p += dataArray[i].score;
    } else {t = t - dataArray[i].score - diff;}
  
    if (t >= 0) {
      printf("%.2lf seconds left.\n", t);
      printf("Your current score is %d\n", p);
    } else {puts("TIME UP! Game over...");}
  }
  return p;
}
