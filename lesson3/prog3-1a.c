#include <stdio.h>
int main(void){
    FILE *fp;
    char line[1000];

    fp=fopen("prog2-1a.c","r");
    if(fp==NULL){
        printf("エラー発生");
        return -1;
    }

    while((fgets(line, sizeof(line), fp)) != NULL){
        printf("%s",line);
    }
    
    fclose(fp);
    return 0;
}



