#include <stdlib.h>
#include <stdio.h>
//#include "mysort.h"

int a, b, c, i, arraylength, temp, boolean;
int boolean = -1; 
int *ptrboolean = &boolean; 

void verifyOrder(int *array){

	arraylength = 100; 
	c = 0; 	

	for(a = 1; a < arraylength; a++){
			if(array[a] < array[a-1]){
				*ptrboolean = -1;
				break;   	
			} else {
				*ptrboolean = 0;
			}
	}

	if(boolean == 0){
		printf("%s\n", "Ordered."); 
	} else {
		printf("%s\n", "Program failed."); 
	}
 		
 		
}


