/* first come first served disk scheduling */

#include<math.h> 
#include<stdio.h> 
#include<stdlib.h> 

void main() { 
	int i,n,req[50],mov = 0,cp; 
	printf("\n\t\tFIRST COME FIRST SERVE DISK SCHEDULING");
	printf("\n\t\t--------------------------------------\n");
	printf("\n  Enter current position of head: "); 
	scanf("%d",&cp); 
	printf("\n  Enter number of requests: "); 
	scanf("%d",&n); 
	printf("\n  Enter requests: "); 
	for(i = 0;i < n;i++) scanf("%d",&req[i]);
	mov = mov + abs(cp - req[0]); /* abs is used to calculate the absolute value */
	printf("  %d -> %d",cp,req[0]); 
	for(i = 1;i < n;i++) { 
		mov=mov+abs(req[i] - req[i-1]); 
		printf(" -> %d",req[i]); } 
	printf("\n"); printf("\n  Total head movement = %d",mov); 
	printf("\n\n");
}
