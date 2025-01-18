#ifndef HEALPER_H
#define HEALPER_H

#include <limits.h>

#define MAX_SIZE 100
#define MAX_SMALL 6

typedef int labelAdjMat[MAX_SMALL][MAX_SMALL];

typedef struct {
	int u;
	int v;
	int weight;
} edgetype;

typedef struct {
	edgetype edges[MAX_SIZE];
	int size;
} MinHeap;

typedef struct edgeNode{
	edgetype n;
	struct edgeNode* next;
} *edgeList;

// Function to initialize the min-heap
void initMinHeap(MinHeap* heap) {
    heap->size = 0;
}

// Function to get the parent index
int parent(int i) {
    return (i - 1) / 2;
}

// Function to get the left child index
int leftChild(int i) {
    return (2 * i) + 1;
}

// Function to get the right child index
int rightChild(int i) {
    return (2 * i) + 2;
}

// Function to insert a new element into the min-heap
void insert(MinHeap* heap, edgetype edge) {
    if (heap->size == MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    // Insert the new element at the end of the heap
    int i = heap->size;
	heap->edges[i] = edge;
    heap->size++;

    // Bubble up to maintain the min-heap property
    while (i != 0 && heap->edges[parent(i)].weight > heap->edges[i].weight) {
        edgetype temp = heap->edges[i];
        heap->edges[i] = heap->edges[parent(i)];
        heap->edges[parent(i)] = temp;

        i = parent(i);
    }
}

// Function to MinHeapify only the current subtree
void heapifySubtree(MinHeap* heap, int i){
	int smallest = i;
	int left = leftChild(i);
	int right = rightChild(i);

    // Find the smallest among the parent, left child, and right child
    if (left < heap->size && heap->edges[left].weight < heap->edges[smallest].weight) {
        smallest = left;
    }
    if (right < heap->size && heap->edges[right].weight < heap->edges[smallest].weight) {
        smallest = right;
    }

    // If the smallest is not the parent, swap and continue heapifying
    if (smallest != i) {
        edgetype temp = heap->edges[i];
        heap->edges[i] = heap->edges[smallest];
        heap->edges[smallest] = temp;
    }
}


// Function to perform the minHeapify operation
void minHeapify(MinHeap* heap, int i) {
	int smallest = i;
	int left = leftChild(i);
	int right = rightChild(i);

    // Find the smallest among the parent, left child, and right child
    if (left < heap->size && heap->edges[left].weight < heap->edges[smallest].weight) {
        smallest = left;
    }
    if (right < heap->size && heap->edges[right].weight < heap->edges[smallest].weight) {
        smallest = right;
    }

    // If the smallest is not the parent, swap and continue heapifying
    if (smallest != i) {
        edgetype temp = heap->edges[i];
        heap->edges[i] = heap->edges[smallest];
        heap->edges[smallest] = temp;
		minHeapify(heap, smallest);
    }
}

// Function to remove the minimum element (root) from the min-heap
edgetype deleteMin(MinHeap* heap) {
	edgetype root;
	root.u = -1;
	root.v = -1;
	root.weight = -1;

    if (heap->size <= 0) {
        printf("Heap is empty\n");
    } else if (heap->size == 1) {
			heap->size--;
    } else {

    // Save the root value and move the last element to the root
    root = heap->edges[0];
    heap->edges[0] = heap->edges[heap->size - 1];
    heap->size--;

    // Heapify from the root down to restore min-heap property
    minHeapify(heap, 0);

    }
	return root;
}

// Function to print the elements of the heap
//void printHeap(MinHeap* heap) {
//    for (int i = 0; i < heap->size; i++) {
//        printf("%d ", heap->data[i]);
//    }
//    printf("\n");
//}



#endif
