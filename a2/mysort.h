#include <stdlib.h>
#include <stdio.h>

int a, b, c, i, arraylength, temp, boolean;
int boolean = -1; 
int *ptrboolean = &boolean;  


void generateNums(int *array){
	
	arraylength = 100; 

	for(a = 0; a < arraylength; a++){
		array[a] = (rand() % 100) + 1;
		//printf("%d\n", array[a]);  
	}
	
}


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
