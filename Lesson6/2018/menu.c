#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include <time.h>

void menu(){
	int n, success;
	char ch;
	DATA *dataArray = (DATA *)malloc(sizeof(DATA) * MAXLEN);
	int ret=1, score;
	srand((unsigned)time(NULL));

	printf("クイズ:q タイピング:t 終了:e\n");
	printf("menu> ");

	while(ret == 1){
		ch = getchar();

		switch(ch){
			case '\n':
				// 改行時に照準を合わせるため追記
				printf("menu> ");				
        break;

			case 'q':
				input();
				printf("menu> \n");				
				break;

			case 't':
				success = DataReader(dataArray, &n);
				if(success==0){
					score=typing(dataArray,n);
					printf("You got score:%d\n", score);
				}
				printf("menu> \n");
				break;

			case 'e':
        ret=0;
				break;

			default :
				printf("invalid command.\n");

		}
	}

	free(dataArray);
	return;
}
