#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "import.h"

void edge() {
  int ret1, ret2, i, j, label, label1, label2, label3, label4;
  FILE *fpIn, *fpOut;
  IMAGE *imgIn, *imgOut;

  fpIn = fopen("venice.bmp", "r");
  if (fpIn == NULL) {
    puts("error.");
    return;
  }

  imgIn = (IMAGE *)malloc(sizeof(IMAGE));
  imgOut = (IMAGE *)malloc(sizeof(IMAGE));

  ret1 = readImage(fpIn, imgIn);
  if (!ret1) {
    puts("error.");
    return;
  }

  imgOut -> width = imgIn -> width;
  imgOut -> height = imgIn -> height;
  imgOut -> depth = imgIn -> depth;
  imgOut -> pixels = (PIXEL *)malloc(imgOut -> width * imgOut -> height * sizeof(PIXEL));

  for (i = 0; i < imgOut -> width; i++) {
    for (j = 0; j < imgOut -> height; j++) {
      label = getLabel(i, j, imgOut -> width);
      if (i == 0 || j == 0 || i == imgOut -> width - 1 || j == imgOut -> height - 1) {
        imgOut -> pixels[label].r = 0;
        imgOut -> pixels[label].g = 0;
        imgOut -> pixels[label].b = 0;
      } else {
        label1 = getLabel(i + 1, j, imgOut -> width);
        label2 = getLabel(i - 1, j, imgOut -> width);
        label3 = getLabel(i, j + 1, imgOut -> width);
        label4 = getLabel(i, j - 1, imgOut -> width);

        imgOut -> pixels[label].r = 255 - sqrt(pow(((imgIn -> pixels[label1].r - imgIn -> pixels[label2].r) / 2), 2.0) + pow(((imgIn -> pixels[label3].r - imgIn -> pixels[label4].r) / 2), 2.0));
        imgOut -> pixels[label].g = 255 - sqrt(pow(((imgIn -> pixels[label1].g - imgIn -> pixels[label2].g) / 2), 2.0) + pow(((imgIn -> pixels[label3].g - imgIn -> pixels[label4].g) / 2), 2.0));
        imgOut -> pixels[label].b = 255 - sqrt(pow(((imgIn -> pixels[label1].b - imgIn -> pixels[label2].b) / 2), 2.0) + pow(((imgIn -> pixels[label3].b - imgIn -> pixels[label4].b) / 2), 2.0));
      }
    }
  }

  fpOut = fopen("venice-edge.bmp", "w");
  if (fpOut == NULL) {
    puts("error.");
    return;
  }

  ret2 = saveImage(fpOut, imgOut);
  if (!ret2) {
    puts("error.");
    return;
  }

  free(imgIn);
  free(imgOut);
  free(imgOut -> pixels);
  fclose(fpIn);
  fclose(fpOut);
}
