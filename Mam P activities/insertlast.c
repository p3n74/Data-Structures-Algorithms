#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "back.c"
#include "back.h"

#include "insertlast.h"

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




int main(){

	srand(time(NULL));
	List L;

	initList(&L);
	createList(&L);
	printList(L);
	
	insertLast(&L, 10);
	printList(L);

    return 0;

}
