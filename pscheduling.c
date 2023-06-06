#include <stdio.h>
#define MAX 10

/* global variables */
typedef struct
{
	int pid;
	int burst_time;
	int wait_time;
	int turnaround_time;
	int priority;
} Process;

void main(){
	int n,i,j,temp,temp1,temp2;
	Process p[MAX];
	printf("\n  PRIORITY SCHEDULING");
	printf("\n  -------------------\n");
	printf("\n  Enter no of processes? ");
	scanf("%d",&n);
	printf("\n  	    PROCESS ID  BURST TIME  PRIORITY\n");
	for(i=0;i<n;i++){
		printf("  Process %d ",i+1);
		scanf("%d %d %d",&p[i].pid,&p[i].burst_time,&p[i].priority);
	}
	
	// sort the processes according to the priorities they have
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(p[j].priority>p[j+1].priority){
				temp1=p[j].pid;
				p[j].pid=p[j+1].pid;
				p[j+1].pid=temp1;
				/* sort the priorities */
				temp=p[j].priority;
				p[j].priority=p[j+1].priority;
				p[j+1].priority=temp;
				/* sort the burst times */
				temp2=p[j].burst_time;
				p[j].burst_time=p[j+1].burst_time;
				p[j+1].burst_time=temp2;
			}
		}
	}
	
	// calculate waiting time and turnaround time for each process
	for(i=0;i<n;i++){
		if(i==0){
			p[0].wait_time=0;
			p[0].turnaround_time=p[0].burst_time;
		}
		else{
			p[i].wait_time=p[i-1].burst_time+p[i-1].wait_time;
			p[i].turnaround_time=p[i].burst_time+p[i].wait_time;
		}
		
	}
	
	/* display the process tables */
	printf("\n  +------------+--------------+------------+----------+-----------------+");
	printf("\n  | PROCESS ID | WAITING TIME | BURST TIME | PRIORITY | TURNAROUND TIME |");
	printf("\n  +------------+--------------+------------+----------+-----------------+");
	for(i=0;i<n;i++){
		printf("\n  |    %d     | %d       | %d       |   %d     |    %d|",p[i].pid,p[i].wait_time,p[i].burst_time,p[i].priority,p[i].turnaround_time);
	}
	printf("\n  +------------+--------------+------------+----------+-----------------+");
	printf("\n");
	
}
