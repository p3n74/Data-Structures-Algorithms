#ifndef BACK_H
#define BACK_H

typedef struct node {
    int data;
    struct node *next;
} *List, node;

void createList(List *a);
void printList(List a);
int genRand(int max, int min);
void createRandomListLength(List *a);
void initList(List* L);



void sortList(List* L);
List getTail(List L);
List partition(List head, List end, List* newHead, List* newEnd);
List quickSortRecursive(List head, List end);
#endif
