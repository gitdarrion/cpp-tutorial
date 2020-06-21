#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <pthread.h>
#include "maestromatrix.h"

using namespace std;

int rows = 0; 
int cols = 0; 
matrix* m; 

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER; 

void* threadProduct(void* param){
	int count = 0; 
	int* indices = (int *) param;
	pthread_mutex_lock(&count_mutex);
		m->computeProducts(indices[0], indices[1], indices[2]);
 	pthread_mutex_unlock(&count_mutex); 
	
	return NULL; 
}

int main(int argc, char *argv[])
{

if(argc!=3) {fprintf(stderr,"usage: %s <p> <q>\n",argv[0]);exit(-1);}

rows=atoi(argv[1]);
cols=atoi(argv[2]);
assert(rows>0 && cols>0);

int i, j, k = 0; 
int* indices = (int *)malloc(sizeof(int)*3); 

m = new matrix; 
m->startmatrix(rows, cols); 
m->generateMatrixA();
m->generateMatrixB();  

pthread_t threadid[cols]; 
for(i = 0; i < rows; i++){
	for(j = 0; j < rows; j++){
		for(k = 0; k < cols; k++){
			indices[0] = i; 
			indices[1] = j; 
			indices[2] = k; 
			pthread_create(&threadid[k], NULL, &threadProduct, indices);
			pthread_join(threadid[k], NULL);  
		}
	}
}


m->printallmatrices();
return 0;
}
