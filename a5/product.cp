#include <iostream>
#include <cstdlib>

using namespace std; 

int main(int argc, char *argv[]){

	int a, b, product = 0; 
	int set[4] = {1,2,3,4}; 

	if(argc == 1){
		cout<<"Enter two integers: "<<endl; 
	} else if(argc == 2){
		a = atoi(argv[1]); 
		cout<<"Enter a second integer "<<endl; 
		cin>>b; 
	} else {
		a = atoi(argv[1]); 
		b = atoi(argv[2]); 
	}

	product = a * b; 
	cout<<a<<"*"<<b<<"="<<product<<endl; 

}
