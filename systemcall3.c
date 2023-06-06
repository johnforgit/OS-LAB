#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
	int fd,s,c,num_bytes;
	char msg[50]="file system calls";
	char buff[50];
	printf("\n  I/O System calls");
	printf("\n  ----------------");
	fd = open("word.txt",O_RDWR|O_CREAT);
	if(fd == -1)
		printf("\n  Error in opening file!!");
	else
		printf("\n  File opened successfully!!\n  File descriptor=%d",fd);
		
	s = write(fd,msg,sizeof(msg));
	if(s == -1) printf("\n  Unable to write to file");
	else printf("\n  Message written successfully");
	printf("\n  Reading from the file");
	lseek(fd,0,SEEK_SET);
	num_bytes = read(fd,buff,sizeof(msg));
	if(num_bytes == -1)
		printf("\n  Error in reading from file");
	else{
		printf("\n  Message is:%s",buff);
		printf("\n  No of bytes read is:%d",num_bytes);
		printf("\n  File read successfully!!");
	}	
		
	c = close(fd);
	if(c == -1){
		printf("\n  Error in closing file!!");
		return -1;
	}
	else printf("\n  File closed successfully!!");
	printf("\n");
	return 0;
}
