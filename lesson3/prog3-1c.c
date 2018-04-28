#include <stdio.h>
int main(void){
	FILE *fp;
    char line[1000];
    int i=1;
   
    if((fp = fopen("prog2-1a-line.txt","w"))==NULL){
    	printf("\nファイルをオープンできません。");
    }
    else {
    	// fprintf(fp, "%s",line);
    	while((fgets(line,sizeof(line),fp))!=NULL){
        fprintf("%d:%s",i,line);
        i++;
        }
    }

	fclose(fp);
    return 0;
}
