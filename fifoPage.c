/* FIFO page replacement */

#include<stdio.h>
#include<stdlib.h>

void lookup(int *reference, int lookups, int frames){
	int page_table[frames],readyQueue[frames], frequencies[frames];
	for(int i = 0;i < frames;i++){
		page_table[i] = readyQueue[i]=frequencies[i]=-1;
	}
	int fault=0;
	for(int i = 0;i < lookups;i++) {
		int page = reference[i];
		int isFault = 1;
		for(int j = 0;j < frames;j++) {
			if(readyQueue[j] == page) {
				isFault = 0;
				frequencies[j]++;
				break;
			}
		}
		if(isFault) {
		fault++;
			int inserted=0;
			for(int j=0;j<frames;j++) {
				if(page_table[j] == -1) {
					page_table[j] = page;
					for(int k=0;k<frames;k++) {
						if(readyQueue[k] == -1) {
							readyQueue[k] = page;
							frequencies[k] = 1;
							break;
						}
					}
					inserted = 1;
					break;
				}
			}
			if(!inserted) {
				int p =- 1,q =- 1;
				for(int j = 0;j < frames;j++){
					if(p == -1 || frequencies[j] < frequencies[p]){
					p = j;
				}
			}
			for(int j = 0;j < frames;j++){
				if(readyQueue[p] == page_table[j]){
					q = j;
					break;
				}
			}
			for(int j = p;j < frames-1;j++){
				readyQueue[j] = readyQueue[j+1];
				frequencies[j] = frequencies[j+1];
			}
			readyQueue[frames-1] = page;
			frequencies[frames-1] = 1;
			page_table[q] = page;
		}
	}
	printf("  %d: ",page);
	for(int j = 0;j < frames;j++){
		printf("%d",page_table[j]);
		if(j != frames-1){
			printf(" , ");
		}
	}
	printf("\n");
	
	}
	printf("\n  Total pagefaults: %d",fault);
}

void main(){
	int p,f;
	printf("\n\t\tFIFO PAGE REPLACEMENT");
	printf("\n\t\t---------------------\n");
	printf("\n  Enter number of pages: ");
	scanf("%d",&p);
	int reference[p];
	printf("  Enter reference string: ");
	for(int i = 0;i < p;i++){
		scanf("%d",&reference[i]);
	}
	printf("  Enter number of frames: ");
	scanf("%d",&f);
	lookup(reference,p,f);
	printf("\n\n");
}

