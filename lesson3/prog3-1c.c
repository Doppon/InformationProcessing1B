#include <stdio.h>
int main(void){
	FILE *fp_txt;
    FILE *fp_code;
    char line[1000];
    int i=1;

    fp_txt = fopen("prog2-1a-line.txt","w");
    if(fp_txt == NULL){
    	printf("\nテキストファイルをオープンできませんでした。");
        return -1;
    }
    
    fp_code = fopen("prog2-1a.c","r");    
    if(fp_code == NULL){
    	printf("\nコードファイルをオープンできませんでした。");
        return -1;
    }

    while((fgets(line,sizeof(line),fp_code))!=NULL){
        fprintf(fp_txt,"%d:%s",i,line);
        i++;
    }
    
	fclose(fp_txt);
	fclose(fp_code);
    return 0;
}
