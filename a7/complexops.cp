#include <iostream>
#include <cstdlib>
#include <complex>
#include <pthread.h>
#include "complexops.h"

using namespace std;

void *complex_multiply(void *param){
	
	cout<<"\nMULTIPLICATION THREAD: "<<endl; 

	complex<double> *complex_number_array = (complex<double> *) param; 
	
	complex<double> abi = complex_number_array[0]; 
	complex<double> cdi = complex_number_array[1]; 
	
	complex<double> x = operator*(abi, cdi); 
	cout<<abi<<endl;
	cout<<cdi<<endl; 
	cout<<x<<endl; 
}
void *complex_divide(void *param){

	cout<<"\nDIVISION THREAD: "<<endl; 
	
	complex<double> *complex_number_array = (complex<double> *) param; 
	
	complex<double> abi = complex_number_array[0]; 
	complex<double> cdi = complex_number_array[1]; 
	
	complex<double> x = operator/(abi, cdi); 
	cout<<abi<<endl;
	cout<<cdi<<endl; 
	cout<<x<<endl; 

}
 
