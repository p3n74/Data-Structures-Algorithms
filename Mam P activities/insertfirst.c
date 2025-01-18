#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "insertfirst.h"

// Definition of a List: 

// typedef struct node {
//     int data;
//     struct node *next;
// } *List, node;

// helper functions:

// void createList(List *a);
// void printList(List a);
// int genRand(int max, int min);
// void createRandomListLength(List *a)



int main(){
    srand(time(NULL));

    List L = NULL;

    createList(&L);

    printList(L);

    insertFirst(&L, 67);
    insertFirst(&L, 50);
    insertFirst(&L, 51);

    printList(L);

    return 0;

}
