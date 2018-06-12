#include <stdio.h>
#include <string.h>

char putChar(){
  return 'q';
}

int main(void){
  int data1 = 'A';
  char data2 = 'A';
  printf("%d %d\n",data1++,data2++);
  printf("%c %c\n",data1,data2);

  int key;
  key = putChar();
  printf("key=%c\n",key);
}

