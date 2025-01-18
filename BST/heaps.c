#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

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
void insert(MinHeap* heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    // Insert the new element at the end of the heap
    int i = heap->size;
    heap->data[i] = value;
    heap->size++;

    // Bubble up to maintain the min-heap property
    while (i != 0 && heap->data[parent(i)] > heap->data[i]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[parent(i)];
        heap->data[parent(i)] = temp;

        i = parent(i);
    }
}

// Function to MinHeapify only the current subtree
void heapifySubtree(MinHeap* heap, int i){
    // Find the smallest among the parent, left child, and right child
    if (left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }

    // If the smallest is not the parent, swap and continue heapifying
    if (smallest != i) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
    }
}


// Function to perform the minHeapify operation
void minHeapify(MinHeap* heap, int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    // Find the smallest among the parent, left child, and right child
    if (left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }

    // If the smallest is not the parent, swap and continue heapifying
    if (smallest != i) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[smallest];
        heap->data[smallest] = temp;
        minHeapify(heap, smallest);
    }
}

// Function to remove the minimum element (root) from the min-heap
int deleteMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return INT_MAX;
    }

    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];
    }

    // Save the root value and move the last element to the root
    int root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;

    // Heapify from the root down to restore min-heap property
    minHeapify(heap, 0);

    return root;
}

// Function to print the elements of the heap
void printHeap(MinHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    MinHeap heap;
    initMinHeap(&heap);

    // Inserting elements into the heap
    insert(&heap, 3);
    insert(&heap, 1);
    insert(&heap, 6);
    insert(&heap, 5);
    insert(&heap, 9);
    insert(&heap, 8);

    printf("Min-Heap array: ");
    printHeap(&heap);

    printf("Deleted min element: %d\n", deleteMin(&heap));
    printf("Min-Heap after deletion: ");
    printHeap(&heap);

    return 0;
}

