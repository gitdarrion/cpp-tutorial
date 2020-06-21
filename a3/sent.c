#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size = 100; 
int count = 0; 

void acceptchars(char *pchar){

	int i = 0; 	
	char c; 

	printf("Enter a sentence \n");  

	while((c = getchar()) >= 32 && c <= 126 && pchar != NULL){
		
		if(count == size - 1){
			pchar = realloc(pchar, (sizeof(pchar) * 2)); 
		} else if (c != 32) {
			pchar[count++] = c; 
		}
	}

}

void uppercasechars(char *pchar){
	
	int i = 0; 
	//int length = sizeof(pchar) / sizeof(char); 
	for(i = 0; i < count; i++){
		
		if(pchar[i] >= 97 && pchar[i] <= 122){
			pchar[i] -= 32; 
		}
	}
}

void ordercharacters(char *pchar){
	
	int i, a, b = 0; 
	char temp; 
	int length = sizeof(pchar) / sizeof(char); 
	while(ascending(pchar) == 0){
		for(i = 1; i < count; i++){
			a = (int) pchar[i-1]; 
			b = (int) pchar[i]; 
			if(a > b){
				temp = pchar[i-1]; 
				pchar[i-1] = pchar[i]; 
				pchar[i] = temp; 
			}
		}
	}
}

int ascending(char *pchar){
	
	int i, a, b = 0; 
	int booleanint = 1; 
	int length = sizeof(pchar) / sizeof(char);
	
	for(i = 1; i < count; i++){
		a = (int) pchar[i-1]; 
		b = (int) pchar[i]; 
		if(a > b){
			booleanint = 0; 
			break; 
		}
	}

	return booleanint; 
}

void displaychars(char *pchar){
	
	printf("%s", pchar); 
	printf("\n"); 
}

int main(){

	char *characters = malloc(sizeof(char) * size);    

	acceptchars(characters);
	uppercasechars(characters);
	ordercharacters(characters);  
	displaychars(characters);  

	free(characters); 

	return 0; 
}

