/* Least recently used page replacement */

#include<stdio.h>
#include<stdlib.h>

int referenceArray[25];
int frameArray[5];
int pagefault=0;
int n,m;
int isPageFault(int a){
	for(int l=0;l<m;l++){
		if(frameArray[l] == a){
			return 0;
		}
	}
	pagefault++;
	return 1;
}

void main(){
	int i,j;
	printf("\n  LRU Page Replacement");
	printf("\n  -------------------\n");
	printf("\n  Enter number of pages: ");
	scanf("%d",&n);
	printf("\n  Enter number of frames: ");
	scanf("%d",&m);
	printf("\n  Enter reference string: ");
	for(i = 0;i < n;i++) {
		scanf("%d",&referenceArray[i]);
	}
	for(i = 0;i < m;i++) {
		frameArray[i] =- 1;
	}
	j = 0;
	for(i = 0;i < n;i++) {
		if(isPageFault(referenceArray[i])){
			frameArray[j] = referenceArray[i];
			j = (j + 1)%m;
		}
		printf("  %d: ",referenceArray[i]);
		for(int p = 0;p < m;p++){
			printf("%d", frameArray[p]);
			if(p != m-1){
				printf(" , ");
			}
		}
		printf("\n");
	}
	printf("\n  Total page fault: %d",pagefault);
	printf("\n\n");
}

