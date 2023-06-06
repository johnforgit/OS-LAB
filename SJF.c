/*
 * C Program to Implement SJF Scheduling
 */
 
#include<stdio.h>
int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,totalT=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
 
    //sorting of burst times
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;
 
    //finding the waiting time of all the processes
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
             //individual WT by adding BT of all previous completed processes
            wt[i]+=bt[j];
 
        //total waiting time
        total+=wt[i];   
    }
 
    //average waiting time
    avg_wt=(float)total/n;  
 
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        //turnaround time of individual processes
        tat[i]=bt[i]+wt[i]; 
 
        //total turnaround time
        totalT+=tat[i];      
        printf("\np%d\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    //average turnaround time
    avg_tat=(float)totalT/n;     
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f",avg_tat);
}

/** 
Program Explanation
1. Initialize two array pid[] and bt[] of size 20.
2. Ask the user for number of processes n.
3. Ask the user for process id and burst time for all n processes and store them into pid[] and bt[] respectively.
4. Sort all the processes according to their burst time.
5. Assign waiting time = 0 to the smallest process.
6. Calculate waiting time of each process by using two loops and adding all the burst time of previously completed processes.
7. Print Process Id, Burst Time, waiting time and Turnaround time of each process in tabular manner.
8. Calculate and print turnaround time of each process = bt[i] + wt[i].
9. Add waiting time of all the processes and store it in the variable total.
10. Add turnaround time of all the processes and store it in the variable totalT.
11. Calculate average waiting time as avg_wt = total/n.
12. Calculate average turnaround time as avg_tat = totalT/n;
13. Print average waiting time and average turnaround time.
14. Exit.

*/
