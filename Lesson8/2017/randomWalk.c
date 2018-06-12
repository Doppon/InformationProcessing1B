#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include "randomWalk.h"
#include "imgutil.h" 

void init(POINT *pointArray,int totalPointNum,int initX,int initY){
  int i;
  for(i=0;i<totalPointNum;i++){
    pointArray[i].x=initX;
    pointArray[i].y=initY;
    if(i%3==0){
      pointArray[i].r=255;
      pointArray[i].g=0;
      pointArray[i].b=0;
    }
    if(i%3==1){
      pointArray[i].r=0;
      pointArray[i].g=255;
      pointArray[i].b=0;
    }
    if(i%3==2){
      pointArray[i].r=0;
      pointArray[i].g=0;
      pointArray[i].b=255;
    }
  }
  srand((unsigned)time(NULL));
}

void move(POINT *pointArray,int i,int w,int h){
  int a,b;
  a=rand()%3;
  b=rand()%3;
  if(a==0 && pointArray[i].x<w) pointArray[i].x=pointArray[i].x+1;
  else if(a==1 && pointArray[i].x>0) pointArray[i].x=pointArray[i].x-1;
  else pointArray[i].x=pointArray[i].x;

  if(b==0 && pointArray[i].y<h) pointArray[i].y=pointArray[i].y+1;
  else if(b==1 && pointArray[i].y>0) pointArray[i].y=pointArray[i].y-1;
  else pointArray[i].y=pointArray[i].y;
}

void drawPoints(POINT *pointArray,int w,int h,int totalPointNum,int turns){
  int i,j,k,ret;
  FILE *fp;
  IMAGE *img=(IMAGE*)malloc(sizeof(IMAGE));
  img->width=w;
  img->height=h;
  img->depth=24;
  img->pixels=(PIXEL*)malloc(img->width*img->height*sizeof(PIXEL));
  for(i=0;i<w*h;i++){
    img->pixels[i].r=255;
    img->pixels[i].g=255;
    img->pixels[i].b=255;
  }
  for(i=0;i<turns;i++){
    for(j=0;j<totalPointNum;j++){
      move(pointArray,j,w,h);
      k=getLabel(pointArray[j].x,pointArray[j].y,w);
      img->pixels[k].r=pointArray[j].r;
      img->pixels[k].g=pointArray[j].g;
      img->pixels[k].b=pointArray[j].b;
    }
  }
  fp=fopen("ramdomWalk.bmp","w");
  ret=saveImage(fp,img);
  if(ret!=1){
    printf("Error");
  }
  fclose(fp);
  free(img->pixels);
}
