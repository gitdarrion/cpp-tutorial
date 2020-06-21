#include <stdlib.h>
#include <stdio.h>
//#include "mysort.h"

int a, b, c, i, arraylength, temp, boolean;
int boolean = -1; 
int *ptrboolean = &boolean;  

void sortNums(int *array){

	boolean = -1; 
	arraylength = 100; // modify
	c = 0; 	


	for(i = 0; i < 100; i++){
		for(a = 0; a < arraylength; a++){
		c = array[a]; 
		if(array[a-1] > c){
			temp = array[a]; 
			array[a] = array[a-1]; 
			array[a-1] = temp; 		
		}				
	}
	
	}	

	for(a = 0; a <arraylength; a++){
		printf("%d\n", array[a]);
	}

}


