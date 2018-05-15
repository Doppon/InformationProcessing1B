#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quiz.h"

int quizReader(QUIZ *quiz, int *n)
{
  FILE *fp;
  int i = 0;

  fp = fopen("quiz.txt", "r");
  if (fp == NULL) {
    puts("invalid quiz file");
    return -1;
  }

  while (fscanf(fp, " %[^,],%[^,],%[^,],%d", quiz[i].question, quiz[i].ans1, quiz[i].ans2, &quiz[i].correct_ans) != EOF && i < N) {
    i++;
  }
  *n = i;

  fclose(fp);
  return 0;
}

void input(){
  int i = 0, n, ans, p = 0;

  QUIZ *quiz = (QUIZ *)malloc(sizeof(QUIZ) * N);
  if((QUIZ *)malloc(sizeof(QUIZ) * N) == NULL){
    puts("invalid quiz file");
    return;
  }

  quizReader(quiz, &n);

  while (i < n) {
    printf("%s\n", quiz[i].question);
    printf("1:%s 2:%s\n", quiz[i].ans1, quiz[i].ans2);
    scanf("%d", &ans);
    if(ans == quiz[i].correct_ans){
      puts("CORRECT!");
      p += 5;
    } else {
      puts("WRONG!");
    }
    i++;
    printf("\n");
  }

  printf("Congrat!\n");
  printf("score:%d\n", p);
}
