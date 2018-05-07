#include <stdio.h>
double x,y;

int solve(double a, double b, double c, double d, double p, double q);

int main(void){
  double a, b, c, d, p, q;

  // 2018年度版の値
  // double a = 2.0;
  // double b = -1.0;
  // double c = 1.0;
  // double d = 2.0;
  // double p = 15.0;
  // double q = 5.0;

  printf("計算したい値を入力してください.\n");
  printf("a:"); scanf("%lf",&a);
  printf("b:"); scanf("%lf",&b);
  printf("c:"); scanf("%lf",&c);
  printf("d:"); scanf("%lf",&d);

  printf("p:"); scanf("%lf",&p);
  printf("q:"); scanf("%lf",&q);

  solve(a, b, c, d, p, q);
  printf("x = %f,",x); printf("y = %f\n",y);
}

int solve(double a, double b, double c, double d, double p, double q){
  double det;
  det = a * d - b * c;
  if(det == 0){
    printf("det = 0");
    return 0;
  }
  else{
    x = (1 / det) * ( p * d + q * (-b) );
    y = (1 / det) * ( p * (-c) + q * a );
    return 1;
  }
}
