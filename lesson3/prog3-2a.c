#include <stdio.h>
int main(void){
    FILE *csv;
    char line[1000];

    csv = fopen("2018_population.csv","r");
    if(csv==NULL){
        printf("ファイルが開けませんでした。\n");
        return -1;
    }

    while((fgets(line, sizeof(line), csv)) != NULL){
        printf("%s",line);
    }
    
    fclose(csv);
    return 0;
}

