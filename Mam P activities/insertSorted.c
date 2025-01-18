#include <stdio.h>
#include <stdlib.h>

#include "insertSorted.h"

// Definition of a List: 

// typedef struct node {
//     int data;
//     struct node *next;
// } *List, node;

// helper functions:

// void createList(List *a); Creates a linked list of 5 elements
// void printList(List a); Prints a list

// int genRand(int max, int min); Creates a random number
// void createRandomListLength(List *a) Creates a linked list with a random length


// Tasks:
// void insertFirst(parameter 1, parameter 2);
// void insertLast(parameter 1, parameter 2);
// void insertSorted(parameter 1, parameter 2);
//
// void deleteFirst(parameter 1);
// void deleteLast(parameter 1);
//
// void deleteValue(parameter 1, paremeter 2);
// void deleteAllInstances(parameter 1, parameter 2);
//
// BONUS:
//
// int findMiddle(parameter 1); Goal - Return the middle element of the list in O(N)
//
// int insertNFromEnd(parameter 1, parameter 2); Goal - Insert a value that is N nodes from the end in O(N)


int main(){

	srand(time(NULL));
	List L;
	initList(&L);
	createList(&L);
	printList(L);
	
	sortList(&L);
	printList(L);
	insertSorted(&L, 10);
	printList(L);
    return 0;

}
