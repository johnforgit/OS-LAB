#include<stdio.h>
#include<stdlib.h>

int main() {
	int i,j,seek=0,n,size,d[100],disk,temp,max,dloc;
	float avg;
	printf("\n\t\tSCAN");
	printf("\n\t\t----\n");
	printf("\n  Enter total disk size: ");
	scanf("%d",&size);
	printf("\n  Enter size of the request queue: ");
	scanf("%d",&n);
	printf("\n  Enter queue of disk positions: ");
	for(i=0;i<n;i++) scanf("%d",&d[i]);
	printf("\n  Enter head position: ");
	scanf("%d",&disk);
	d[n]=disk;
	for(i = 0;i <= n;i++) {
		for(j = 0;j <= n;j++) {
   			if(d[i] > d[j]) {
        		temp = d[i];
    			d[i] = d[j];
    			d[j] = temp;
   			}
  		}
 	}
 	max=d[n];
 	for(i = 0;i <= n;i++) {
  		if(d[i] == disk) {
			dloc = i;
   			break;
  		}
 	}
 	for(i = dloc;i >= 0;i--){
  		printf("  %d-->",d[i]);
 	}
 	printf("199-->");
 	for(i = dloc+1;i <= n;i++){
  		printf("  %d-->",d[i]);
 	}
 	printf("%d",d[i]);
 	seek = disk + max;
 	printf("\n  Total seek time is : %d",seek);
 	avg = seek/(float)n;
 	printf("\n  Average seek time is : %f",avg);
	printf("\n\n");
 	return 0;
}

