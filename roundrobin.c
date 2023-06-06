#include<stdio.h>
#define MAX 10
 
int main(){
	
	int n;
    	printf("\n\t\t  ROUND ROBIN SCHEDULING");
    	printf("\n\t\t  ----------------------");
    	printf("\n\n  Enter no of processes? ");
    	scanf("%d", &n);
    	int wait_time = 0, ta_time = 0, arr_time[MAX], burst_time[MAX], temp_burst[MAX];
    	int x = n;
    	
    	/* get process details */
    	printf("\n             ARRIVAL TIME BURST TIME\n");
    	for(int i = 0; i < n; i++){
        	printf("  Process %d ", i + 1);
        	scanf("%d %d",&arr_time[i],&burst_time[i]);
        	temp_burst[i] = burst_time[i];
    	}
 
    	//Input time slot
    	int quant;
    	printf("\n  Enter Time Quanta: ");
    	scanf("%d", &quant);
 
    	/* Total indicates total time 
    	counter indicates which process is executed*/
    	int total = 0,  counter = 0,i;
    	printf("\n  +------------+------------+-----------------+--------------+");
    	printf("\n  | PROCESS ID | BURST TIME | TURNAROUND TIME | WAITING TIME |");
    	printf("\n  +------------+------------+-----------------+--------------+");
    	for(total=0,i = 0;x!=0;){
        	// define the conditions
        	if(temp_burst[i] <= quant && temp_burst[i] > 0){  
            		total = total + temp_burst[i];  
            		temp_burst[i] = 0;  
            		counter=1;  
        	}    
        	else if(temp_burst[i] > 0){  
            		temp_burst[i] = temp_burst[i] - quant;  
            		total += quant;    
        	}
        	if(temp_burst[i]==0 && counter==1){  
            		x--; //decrement the process no.  
            		printf("\n  |     %d      |      %d     |       %d        |       %d       |", i+1, burst_time[i],
			total-arr_time[i], total-arr_time[i]-burst_time[i]);  
            		wait_time = wait_time + total-arr_time[i] - burst_time[i];  
            		ta_time += total - arr_time[i];  
            		counter=0;     
        	}  
        	if(i==n-1) i=0;   
        	else if(arr_time[i+1]<=total){
            		i++;  
        	}  
        	else
            	i=0;   
    	}  
	printf("\n  +------------+------------+-----------------+--------------+");
	
    	float average_wait_time = wait_time * 1.0 / n;
    	float average_turnaround_time = ta_time * 1.0 / n;
    	printf("\n\n  Avg Waiting Time: %f", average_wait_time);
    	printf("\n  Avg Turnaround Time: %f", average_turnaround_time);
    	printf("\n\n");
    	return 0;
}
