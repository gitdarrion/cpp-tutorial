#include <stdlib.h>
#include <stdio.h>
//#include "mysort.h"

int a, arraylength;

void generateNums(int *array){
	
	arraylength = 100; 

	for(a = 0; a < arraylength; a++){
		array[a] = (rand() % 100) + 1;
		//printf("%d\n", array[a]);  
	}
	
}


