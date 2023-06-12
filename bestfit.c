/* BEST FIT MEMORY ALLOCATION */

#include<stdio.h>
#define max 25

void main() {
	int frag[max],b[max],f[max],i,j,nb,nf,temp,lowest=10000;
	int bf[max],ff[max];
	printf("\n\t\tBEST FIT MEMORY ALLOCATION");
	printf("\n\t\t--------------------------\n");
	printf("\n  Enter the number of blocks: ");
	scanf("%d",&nb);
	printf("\n  Enter the number of files: ");
	scanf("%d",&nf);
	printf("\n  Enter the size of the blocks: ");
	for(i = 1;i <= nb;i++)
		scanf("%d",&b[i]);
	printf("\n  Enter the size of the files: ");
	for(i=1;i<=nf;i++)
		scanf("%d",&f[i]);
	for(i = 1;i <= nf;i++) {
		for(j = 1;j <= nb;j++) {
		if(bf[j] != 1) {
			temp = b[j] - f[i];
			if(temp >= 0)
				if(lowest > temp) {
					ff[i]=j;
					lowest=temp;
				}
		}
		}
		frag[i]=lowest;
		bf[ff[i]]=1;
		lowest=10000;
	}

	printf("\n  File No\tFile Size\tBlock No\tBlock Size\tFragment");
	for(i=1;i<=nf && ff[i]!=0;i++)
	printf("\n  %d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
	printf("\n\n");
}
