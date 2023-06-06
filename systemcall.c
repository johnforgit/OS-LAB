#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t p;
	printf("\n  PROCESS CREATION\n  ----------------");
	printf("\n");
	p=fork();
	printf("\n  Process created using fork()");
	if(p==-1) printf("\n  Error!!");
	if(p==0){
		printf("\n  Inside child process");
		printf("\n  Child process id: %d",getpid());
		printf("\n  Child's parent id: %d",getppid());
	}
	else{
		printf("\n  Inside parent process");
		printf("\n  parent process id: %d",getpid());
	}
	printf("\n");
	return 0;
} 
