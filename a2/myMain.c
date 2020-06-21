#include <stdio.h>
#include "mysort.h"


int main(){
	
	int array[100]; 
	generateNums(array);  
	sortNums(array); 
	verifyOrder(array); 
	return 0; 
}
