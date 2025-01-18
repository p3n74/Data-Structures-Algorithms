#ifndef BACK_H
#define BACK_H

typedef struct node {
    int data;
    struct node *next;
} *List, node;

typedef struct intarraynode{
    int list[500];
    int count;
    int duplicates;
} intarraynode;

typedef struct doublenode{
    int data;
    struct doublenode* next;
    struct doublenode* prev;
} *dList, doublenode;

void createList(List *a);
void printList(List a);
int genRand(int max, int min);
void removeduplicates(intarraynode *myarray, int x, int i);
intarraynode *genRandListUnique();
void createList2(intarraynode *a, dList *b);

#endif