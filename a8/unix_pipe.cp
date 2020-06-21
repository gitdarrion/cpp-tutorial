#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <iostream>
#include <complex>
#include <cstdlib>

#define BUFFER_SIZE 25
#define READ_END	0
#define WRITE_END	1

using namespace std; 

pthread_mutex_t mute = 1; 

complex<double> cnum(1,2); 
complex<double> *c_write = cnum(1,2); 
c_write[1] = cnum; 
complex<double> *c_read;
pid_t pid;
int fd[2];
	

int main(void)
{
	
	cout<<c_write[0]<<endl; 

	/* create the pipe */
	if (pipe(fd) == -1) {
		fprintf(stderr,"Pipe failed");
		return 1;
	}

	/* now fork a child process */
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork failed");
		return 1;
	}

	if (pid > 0) {  /* parent process */
	
	pthread_t thread1;
	
		pthread_create(&thread1, NULL, read, (void *) 1); 
		pthread_join(thread1, NULL); 
	}
	else { /* child process */
	pthread_t thread2; 
	
		pthread_create(&thread2, NULL, read, (void *) 2); 
		pthread_join(thread2, NULL); 
	}

	return 0;
}

void* write(void *param){
/* close the unused end of the pipe */
		close(fd[READ_END]);

		/* write to the pipe */
		write_to_pipe(fd[WRITE_END]); 

		/* close the write end of the pipe */
		close(fd[WRITE_END]);
}

void* read(void *param){
		/* close the unused end of the pipe */
		close(fd[WRITE_END]);

		/* read from the pipe */
		read_from_pipe(fd[READ_END]); 
		cout<<c_read[0]<<endl; 

		/* close the write end of the pipe */
		close(fd[READ_END]);
}
