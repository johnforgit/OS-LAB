#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

void main(){
	void *shared_memory;
	char buff[100];
	int shmid;
	shmid = shmget((key_t)1122,1024,0666|IPC_CREAT);
	printf("\n  Shared memory segment: %d",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("\n  Process attached the shared memory segment at: %p",shared_memory);
	printf("\n  Enter data: ");
	read(0,buff,sizeof(buff));
	strcpy(shared_memory,buff);
	printf("\n  Data written: %s",(char*)shared_memory);
}
