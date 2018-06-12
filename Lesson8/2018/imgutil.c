#include <stdio.h>
#include "imgutil.h"

long int getLabel(int x, int y, int width){
  return y * width + x -1;
}
