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
1. Input the no of processes
2. Get the burst time of each process
3. For the first process there is no waiting time. It executes as soon as it arrives. 
   set p[0].wait_time = 0
   set p[0].turnaround_time = p[0].burst_time
