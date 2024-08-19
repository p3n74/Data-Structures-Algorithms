#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "back.h"

int genRand(int max, int min){

    // add srand(time(NULL)); to any code calling this helper

    int randomNum = (rand() % max) + min;

    return randomNum; 

}

void createList(List *a){
    List *trav;
    for(int i = 5; i > 0; i--){
        for(trav = a; *trav != NULL; trav = &(*trav)->next){}
            node *temp = (node *)malloc(sizeof(node));
            temp->data = genRand(10, 1);
            temp->next = NULL;
            *trav = temp;
    }
}

void printList(List a){
    List trav;
    printf("\n\t");
    for(trav = a; trav->next != NULL; trav = trav->next){
        printf("%d -> ", trav->data);
    }
    printf("%d", trav->data);
}

void createRandomListLength(List *a){
    List *trav;
    int length;

    for(length = genRand(10, 5); length > 0; length--){
        for(trav = a; *trav != NULL ; trav = &(*trav)->next){}
            node *temp = (node *)malloc(sizeof(node));
            temp->data = genRand(13,1);
            temp->next = NULL;
            *trav = temp;
    }
}