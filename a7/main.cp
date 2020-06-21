#include <iostream>
#include <cstdlib>
#include <complex>
#include <pthread.h>
#include "complexops.h"

using namespace std; 

double a, b, c, d = 0; 
void* status; 

int main(int argc, char *argv[]){
	
	if(argc <= 4){
		cout<<"Too few arguments."<<endl;
		exit(-1); 
	} else {
/*		Set values					*/
		a = atof(argv[1]); 
		b = atof(argv[2]); 
		c = atof(argv[3]); 
		d = atof(argv[4]); 
		
/*		Check if c or d equal 0 			*/
		if(c == 0 || d == 0){
			cout<<"ERROR: Neither c nor d may equal 0."<<endl;
			exit(-1); 
		}
		
/*		Create complex types				*/
		complex<double> complex_ab (a, b); 
		complex<double> complex_cd (c, d); 
		
/*		Create array of complex types			*/
		complex<double>* complex_number_array = new complex<double>[2]; 
		complex_number_array[0] = complex_ab;
		complex_number_array[1] = complex_cd; 
	
/*		Create threads					*/
		pthread_t threads[2]; 
		(void)pthread_create(&threads[0], NULL, complex_multiply, (void *)complex_number_array);
		(void)pthread_create(&threads[1], NULL, complex_divide, (void *)complex_number_array); 

/*		Join threads					*/
		pthread_join(threads[0], &status); 
		pthread_join(threads[1], &status); 
	}
	
	
return 0; 

}
