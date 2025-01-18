#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {

	int data;
	struct node* LC;
	struct node* RC;

} node,*tree;

typedef struct heap {
	
	int data[MAX];
	int size;

} heap;

void initHeap(heap* heap){

	heap->size = 0;

}

int parent(int i){

	return ((i -1) / 2);
}

int rightChild(int i){

	return ( (2 * i) + 1);

}

int leftChild(int i){

	return ( (2 * i) + 2);
}


void insert(heap* heap, int value){

	if (heap->size == MAX){
		printf("FULL\n");
	} else {

		int i = heap->size;
		heap->data[i] = value;
		heap->size++;

		int temp;

		for(
				;i != 0 && heap->data[parent(i)] > heap->data[i]; i = parent(i)){
			
			temp = heap->data[i];
			heap->data[i] = heap->data[parent(i)];
			heap->data[parent(i)] = temp;

		}
	}
}

void minHeap(heap* heap, int i){

	int smallest = i;
	int left = leftChild(i);
	int right = rightChild(i);

	if (left < heap->size && heap->data[left] < heap->data[smallest]){

		smallest = left;
	}

	if (right < heap->size && heap->data[right] < heap->data[smallest]){

		smallest = right;
	}

	if (smallest != i){

		int temp = heap->data[i];
		
		heap->data[i] = heap->data[smallest];
		heap->data[smallest] = temp;
		minHeap(heap, smallest);
	}
}

// This version will sort it while deleteminning
//
void deleteMin(heap* heap){
	
	int root;
	int temp;

	if (heap->size <= 0){
		printf("Heap is empty\n");
	} else {

		if (heap->size == 1){
			heap->size--;
		} else {

			root = heap->data[0];
			
			// swapping
			//
			heap->data[0] = heap->data[heap->size - 1];
			heap->data[heap->size - 1] = root;

			minHeap(heap, 0);
		}
	}
}

// Function to print the elements of the heap
void printHeap(heap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}


int main(){
	
	heap H;
	initHeap(&H);
	
	
	insert(&H, 6);
	insert(&H, 2);
	insert(&H, 3);

	printHeap(&H);


	return 0;

}

