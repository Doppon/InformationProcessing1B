#include <stdio.h>
int solve(double a, double b, double c, double d, double p, double f);

int main(void){
  double a = 2.0;
  double b = -1.0;
  double c = 1.0;
  double d = 2.0;
  double p = 15.0;
  double q = 5.0;

  solve(a, b, c, d, p, q);
}

int solve(double a, double b, double c, double d, double p, double f){
  double det;
  det = a * d - b * c;
  if(det == 0){
    printf("det = 0");
    return 0;
  }
  else{     
    return 1;
  }
}

