#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

void main(){
	void* shared_memory;
	char buff[100];
	int shmid;
	printf("\n  Shared memory segment is %d",shmid);
	shared_memory = shmat(shmid,NULL,0);
	printf("\n  Process attached the shared memory segment at %p",shared_memory);
	printf("\n  Data written is: %s",(char*)shared_memory);
}
