#ifndef BACK_H
#define BACK_H
#define MAX 10

typedef struct node {
    char data;
    int next;
} node;

typedef struct virtualHeap{
    node nodes[MAX];
    int avail;
} virtualHeap;


int genRand(int max, int min);

#endif