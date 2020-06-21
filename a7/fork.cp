#include <iostream>
#include <cstdlib>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std; 

string toLowerCase(string lowercase){
	int i = 0; 
	while(i < lowercase.length()){
		if(lowercase.at(i) >= 65 && lowercase.at(i) <= 90)
			lowercase.at(i)+=32; 
		i++; 
	}
	return lowercase; 
}

string toUpperCase(string uppercase){
	int i = 0; 
	while(i < uppercase.length()){
		if(uppercase.at(i) >= 97 && uppercase.at(i) <= 122)
			uppercase.at(i)-=32; 
		i++; 
	}
	return uppercase; 
}

int main(int argc, char* argv[]){
	int i = 1; 
	int j = 0; 
	string lowercase; 
	string uppercase; 
	pid_t pid = fork(); 

	if(pid == 0){
		cout<<"\n\nChild process: "<<endl; 
		while(argv[i]){
			if(i == argc-1){
				lowercase += argv[i]; 
				i++; 
			} else {
				lowercase += argv[i];
				lowercase += ' '; 
				i++; 
			}
		}
		lowercase = toLowerCase(lowercase); 
		cout<<lowercase<<"\n"<<endl;
	} else {
		cout<<"\n\nParent process: "<<endl;
		while(argv[i]){ 
			if(i == argc-1){
				uppercase += argv[i]; 
				i++;
			} else {
				uppercase += argv[i]; 
				uppercase += ' '; 
				i++; 
			}
		}
		uppercase = toUpperCase(uppercase); 
		cout<<uppercase<<"\n"<<endl; 
	}
	exit(0); 

return 0; 
}
