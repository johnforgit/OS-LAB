/**
    First come first served scheduling algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

/** global variables */
typedef struct{
    int pid;
    int burst_time;
    int wait_time;
    int turnaround_time;
} Process;

void main(){
    int n,i,sum_waittime=0,sum_turnaroundtime=0;
    Process p[MAX];
    puts("\n FIRST COME FIRST SERVED SCHEDULING");
    puts("\n ----------------------------------");
    printf("\n Enter no of processes? ");
    scanf("%d",&n);
    puts("\n Enter processes and their burst times");
    puts("\n            PROCESS ID \t BURST TIME");
    /** get process details here */
    for(i=0;i<n;i++){
        printf("\n Process %d - ",i+1);
        scanf("%d",&p[i].pid);
        scanf("%d",&p[i].burst_time);
        p[i].turnaround_time=p[i].wait_time=0;
    }
    p[0].turnaround_time=p[0].burst_time;

    /** calculate times for other processes */
    for(i=1;i<n;i++){
        p[i].wait_time=p[i-1].burst_time+p[i-1].wait_time;
        p[i].turnaround_time=p[i].wait_time+p[i].burst_time;
    }

    /** calculate total waiting time and turnaround time */
    for(i=0;i<n;i++){
        sum_turnaroundtime+=p[i].turnaround_time;
        sum_waittime+=p[i].wait_time;
    }
    puts("\n\t\t +------------+------------+--------------+----------------+");
    puts("\n\t\t | PROCESS ID | BURST TIME | WAITING TIME | TURNAROUND TIME|");
    puts("\n\t\t +------------+------------+--------------+----------------+");
    for(i=0;i<n;i++){
        printf("\n\t\t |    %2d    |     %2d        |     %2d       |     %2d        |",
    p[i].pid,p[i].burst_time,p[i].wait_time,p[i].turnaround_time);
    }
    puts("\n\t\t +---------------------------------------------------------+");


}
