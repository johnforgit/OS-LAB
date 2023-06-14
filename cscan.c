/* C-SCAN */

#include<stdio.h>
#include<stdlib.h>

int main() {
	int i,j,seek = 0,n,size,d[100],disk;
	int temp,max,dloc;
	float avg;
	printf("\n  C-SCAN DISK SCHEDULING");
	printf("\n  ----------------------\n");
	printf("\n  Enter total disk size: ");
	scanf("%d",&size);
	printf("  Enter size of the request queue: ");
	scanf("%d",&n);
	printf("  Enter requests: ");
	for(i=0;i<n;i++){
		scanf("%d",&d[i]);
	}
	printf("  Enter head position: ");
 	scanf("%d",&disk);
 	
 	d[n]=disk;
 	for(i = 0;i <= n;i++){
  		for(j = 0;j <= n;j++){
   			if(d[i] > d[j]){
    			temp = d[i];
    			d[i] = d[j];
    			d[j] = temp;
   			}
  		}
 	}
 	max = d[n];
 	for(i = 0;i <= n;i++){
  		if(d[i] == disk){
   			dloc=i;
   			break;
  		}
 	}
 	for(i = dloc;i <= n;i++){
  		printf("%d  -->",d[i]);
 	}
 	printf("0-->");
 	printf("199-->");
 	for(i = 0;i < dloc;i++){
  		printf("  %d-->",d[i]);
 	}
 	printf("%d",d[i]);
 	seek = size-1+((size-1)-d[dloc])+d[dloc-1];
 	printf("\n  Total seek time is : %d",seek);
 	avg=seek/(float)n;
 	printf("\n  Average seek time is : %f",avg);
 	printf("\n\n");
 	return 0;
}
