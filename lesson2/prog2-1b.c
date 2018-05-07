#include <stdio.h>
#include <stdlib.h>
int main(void){
	int *array1=(int *)malloc(sizeof(int)*10000);
	int *array2=(int *)malloc(sizeof(int)*10000);
	int i;
	for(i = 0; i < 10000; ++i){
		*(array1+i) = 2 * i - 1;
		*(array2+i) = 2 * i;
	}
	int *tmp;
	int change_times;	
	for(change_times = 0; change_times < 2000; ++change_times){
		tmp = array1;
		array1 = array2;
		array2 = tmp;
	}
	printf("終了\n");
	return 0;
}
