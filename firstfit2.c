/* first fit memory allocation */

#include<stdio.h>
 
void main() {
	int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
	for(i = 0; i < 10; i++) {
		flags[i] = 0;
		allocation[i] = -1;
	}
	printf("\n  FIRST FIT MEMORY ALLOCATION");
	printf("\n  ---------------------------\n");
	printf("\n  Enter no. of blocks: ");
	scanf("%d", &bno);
	printf("\n  Enter size of each block: ");
	for(i = 0; i < bno; i++)
		scanf("%d", &bsize[i]);
	printf("\n  Enter no. of processes: ");
	scanf("%d", &pno);
	printf("\n  Enter size of each process: ");
	for(i = 0; i < pno; i++)
		scanf("%d", &psize[i]);
	for(i = 0; i < pno; i++)         //allocation as per first fit
		for(j = 0; j < bno; j++)
			if(flags[j] == 0 && bsize[j] >= psize[i]) {
				allocation[j] = i;
				flags[j] = 1;
				break;
			}
	//display allocation details
	printf("\n  Block no\tsize\t\tprocess no\tsize");
	for(i = 0; i < bno; i++) {
		printf("\n  %d\t\t%d\t\t", i+1, bsize[i]);
		if(flags[i] == 1)
			printf("%d\t\t%d",allocation[i]+1,psize[allocation[i]]);
		else
			printf("Not allocated");
	}
	printf("\n\n");
}
