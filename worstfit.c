/* WORST FIT MEMORY ALLOCATION */

#include<stdio.h>
#define max 25

void main() {
	int frag[max],b[max],f[max],i,j,nb,nf;
	int bf[max],ff[max],temp,highest=0;
	printf("\n\t\tWORST FIT MEMORY ALLOCATION");
	printf("\n\t\t---------------------------\n");
	
	printf("\n  Enter number of blocks: ");
	scanf("%d",&nb);
	printf("\n  Enter number of processes: ");
	scanf("%d",&nf);
	printf("\n  Enter size of the blocks: ");
	for(i = 1;i <= nb;i++) scanf("%d",&b[i]);
	printf("\n  Enter size of the files: ");
	for(i = 1;i <= nf;i++) scanf("%d",&f[i]);
	
	/*  allocate memory to the processes */
	for(i = 1;i <= nf;i++) {
		for(j = 1;j <= nb;j++) {
			if(bf[j] != 1) {    /* if bf[j] is not allocated */
				temp = b[j] - f[i];
				if(temp >= 0)
					if(highest < temp) {
						ff[i] = j;
						highest = temp;}
			}
		}
		frag[i] = highest;
		bf[ff[i]] = 1;
		highest = 0;
	}
	printf("\n  Process No\tProcess Size\tBlock No\tBlock Size\tFragment");
	for(i = 1;i <= nf;i++)
	printf("\n  %d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
	printf("\n\n");
}
