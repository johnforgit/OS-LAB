# OS-LAB
Programs done in OS lab

## Shell Programming
The first few programs are of shell programming. These include simple arithmetic operations and also calculating the Fibonnaci series

## Processes
Programs to create a process and also to distinguish between a child and parent process are also done

## System Calls
Programs to execute various system calls like exec and directory system calls.

## CPU Scheduling
Various process scheduling techniques used by the CPU are implemented here. They are  
First Come First Serve Scheduling  
Shortest job First Scheduling  
Round Robin Scheduling  
Priority Scheduling

### First Come First Serve Scheduling

struct process  
{  
   int burst_time;    
   int wait_time;  
   int turnaround_time;  
} Process;  
This is the structure used to simulate the process. However one can also use arrays to get the same details of the processes

Algorithm:  
1. Start
2. Input the no of processes(n)  
3. Get the burst time of each process
4. For the first process there is no waiting time. It executes as soon as it arrives.   
   set p[0].wait_time = 0  
   set p[0].turnaround_time = p[0].burst_time
5. for(i = 0;i < n;i++) {  
      p[i].wait_time = p[i-1].wait_time + p[i-1].burst_time;  
      p[i].turnaround_time = p[i].wait_time + p[i].burst_time;  
   }  
6. for(i = 0;i < n;i++) {  
      sumWait += p[i].wait_time;  
      sumTurnaround += p[i].turnaround_time;  
   }
7. Average waiting time = sumWait/n  
8. Average turnaround time = sumTurnaround/n    
9. Display the process table and the Gantt chart
10. Stop
     
