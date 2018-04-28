#include <stdio.h>
int main(void){
	int i,array1[10000],array2[10000];
	for(i = 0; i <10000; i++){
		array1[i] = 2*i-1;
		array2[i] = 2*i;
	}
	int change_times;
	int k,tmp[10000];
	for(change_times = 0; change_times < 2000; ++change_times){
		for(k = 0; k < 10000; k++){
			tmp[k] = array1[k];
			array1[k] = array2[k];
			array2[k] = tmp[k];
		}
	}
	printf("終了\n");
 	return 0;
}
