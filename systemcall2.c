/* fork getpid wait exit system calls */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>

void main(){
	pid_t PID;
	printf("\n  SYSTEM CALLS\n");
	PID = fork();
	if(PID == -1){
		printf("\n  ERROR!!");
		exit(EXIT_FAILURE);
	}
	if(PID == 0){
		printf("\n  CHILD PROCESS");
		printf("\n  Process ID of child is %d",getpid());
		printf("\n  Process ID of child's parent is %d",getppid());
		exit(EXIT_SUCCESS);
	}
	if(PID > 0){
		printf("\n  PARENT PROCESS");
		printf("\n\n  Process ID of parent is %d",getpid());
		wait(NULL);   // waiting for child to finish execution
		printf("\n  End of parent process");
	}
	printf("\n");
}
