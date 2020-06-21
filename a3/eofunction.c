#include <stdio.h>
#include <stdlib.h>


int even(int x){
	
	return x % 2; 
}

int main(){

	int x = 0;
	int *px = &x; 

	printf("Input an integer between 1 and 50 \n");
	scanf("%d", px);   
	
	do{
		if(even(x) == 0){
			x = x / 2; 
			printf("%d\n", x); 
		} else if(even(x) != 0){
			x = (3 * x) + 1; 
			printf("%d\n", x); 
		}
	} while(x != 1);	
	
	return 0; 
}
