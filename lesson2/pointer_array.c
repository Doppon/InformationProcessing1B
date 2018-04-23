#include <stdio.h>
#include <stdlib.h>
int main(void){
  int i;
  int z[100];
  for(i=0; i<100; i++){
    z[i] = 0;
  }

  int *z_pointer = (int *)malloc(sizeof(int)*100);
  for(i=0; i<100; i++){
    *(z_pointer + i) = 0;
  }
}
