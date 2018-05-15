#ifndef QUIZ_H_
#define QUIZ_H_

#define N 100

struct _quiz{
  char question[50];
  char ans1[50];
  char ans2[50];
  int correct_ans;
};

typedef struct _quiz QUIZ;

int  quizReader(QUIZ *quiz, int *n);
void input();

#endif /* QUIZ_H_ */
