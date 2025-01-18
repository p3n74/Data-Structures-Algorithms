#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10


typedef struct node {
    int data;
    int next;
} node;

typedef struct virtualHeap{
    node nodes[MAX];
    int avail;
} virtualHeap;


int genRand(int max, int min){

    // add srand(time(NULL)); to any code calling this helper

    int randomNum = (rand() % max) + min;

    return randomNum; 

}

int intscanner(){
    int temp;
    printf("Input: ");
    scanf("%d", &temp);

    fflush(stdin);

    return temp;
}

void printError(int* errorCode){
    printf("\nERROR:");
    if(*errorCode == 1){
        printf("\n\tLIST IS FULL \n");
    } else if (*errorCode = 2){
        printf("\n\tNo list entered/List Empty");
    }

    *errorCode = 0;
}

