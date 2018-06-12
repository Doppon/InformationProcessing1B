#include <stdio.h>
#include "word.h"

void fwriteWORD(WORD w, FILE *fp){
  int i, num;
  for(i=0; i<2; i++){
    num = w % 256;
    w = w / 256;
    fputc(num, fp);
  }
}

void fwriteDWORD(DWORD dw, FILE *fp){
  int i, num;
  for(i=0; i<4; i++){
    num = dw % 256;
    dw = dw / 256;
    fputc(num, fp);
  }
}
