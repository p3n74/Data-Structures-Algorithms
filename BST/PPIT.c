#include <stdio.h>
#include <stdlib.h>

#include "back.c"
#include "back.h"

#define MAX 0XD

typedef int maxHeapList[MAX];
typedef enum{TRUE, FALSE} Boolean;


Boolean isMaxHeap(maxHeapList heap){
	int i;
	Boolean result = TRUE;

	for(i = 1; i <= heap[0]; i++){
		if(heap[i] < heap[(2 * i)]){
			result = FALSE;
		}
		if(heap[i] < heap[(2 * i + 1)]){
			result = FALSE;
		}
	}

	return result;
}

void initHeap(maxHeapList heap){

	heap[0] = 12;
	int i;
	for(i = 1; i < MAX; i++){
		heap[i] = genRand(10,1);
	}
}

void printHeap(maxHeapList heap){
	int i;
	for(i = 0; i < MAX; i++){
		printf("%d ", heap[i]);
	}
}





int main(){


	srand(time(NULL));

	maxHeapList heap;
	initHeap(heap);
	printHeap(heap);
	
	if(isMaxHeap(heap) == TRUE){
		printf("\nyes");
	} else {
		printf("\nno");
	}
	return 0;

}
