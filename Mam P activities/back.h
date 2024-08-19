#ifndef BACK_H
#define BACK_H

typedef struct node {
    int data;
    struct node *next;
} *List, node;

void createList(List *a);
void printList(List a);
int genRand(int max, int min);

#endif