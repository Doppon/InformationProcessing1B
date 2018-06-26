
#include <stdio.h>
#include <stdlib.h>
#include "import.h"
#include "thicken.h"

int min(int label, int label1, int label2, int label3, int label4) {
  int min;

  min = label;

  if (min > label1) {
    min = label1;
  }
  if (min > label2) {
    min = label2;
  }
  if (min > label3) {
    min = label3;
  }
  if (min > label4) {
    min = label4;
  }

  return min;
}

void thicken() {
  int ret1, ret2, i, j, label, label1, label2, label3, label4;
  FILE *fpIn, *fpOut;
  IMAGE *imgIn, *imgOut;

  fpIn = fopen("venice-edge.bmp", "r");
  if (fpIn == NULL) {
    puts("couldn't open venice-edge.bmp");
    return;
  }

  imgIn = (IMAGE *)malloc(sizeof(IMAGE));
  imgOut = (IMAGE *)malloc(sizeof(IMAGE));

  ret1 = readImage(fpIn, imgIn);
  if (!ret1) {
    puts("couldn't readImage");
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

	imgOut -> pixels[label].r = min(imgIn -> pixels[label].r, imgIn -> pixels[label1].r, imgIn -> pixels[label2].r, imgIn -> pixels[label3].r, imgIn -> pixels[label4].r);
	imgOut -> pixels[label].g = min(imgIn -> pixels[label].g, imgIn -> pixels[label1].g, imgIn -> pixels[label2].g, imgIn -> pixels[label3].g, imgIn -> pixels[label4].g);
	imgOut -> pixels[label].b = min(imgIn -> pixels[label].b, imgIn -> pixels[label1].b, imgIn -> pixels[label2].b, imgIn -> pixels[label3].b, imgIn -> pixels[label4].b);
      }
    }
  }

  fpOut = fopen("venice-t.bmp", "w");
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
