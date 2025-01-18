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

/*
    Generating a random list of unique Numbers.

    We will use the Knuth Algorithm

    im is a counter for the unique numbers that have been added to the list

    in is an index from 0 to N-1 to consider each number in the defined range


    the loop begins from in = 0 to in = N-1, to ensure that all the numbers in the range are evaluated
    while that is going on, we have two conditions- 
    
    the first condition is in < N
    once this condition returns FALSE, the loop ends as there is no more possible unique numbers in the specified range

    the second condition is im < M
    once this condition returns FALSE, the loop ends as the entire list is filled.

    RN is the possible numbers left and RM is how many more NUMBERS WE NEED

    the condition

    rand() % rm < rn

    here, it will generate a random number from 0 to rn - 1. From here if this random number
    is less than the remaining amount of numbers, RM, it is added to the list


*/

void removeduplicates(intarraynode *myarray, int x, int i){

    int y = 0;
    for(; myarray->list[i] != '\0'; i++){
        if((myarray->list[i] == x) && y == 1){
            myarray->list[i] = -1;
            myarray->duplicates++;
            myarray->count--;
        } else if((myarray->list[i] == x) && y == 0){
            y = 1;
        }
    }
}

intarraynode *genRandListUnique(){
    intarraynode *mynode1 = (struct intarraynode *)calloc(1, sizeof(struct intarraynode));

    mynode1->count = 0;
    mynode1->duplicates = 0;

    int i; 
       
       for(i = 0; i < 500; i++, mynode1->count++){
        mynode1->list[i] = genRand(3000, 1);
       }

    for(i = 0; mynode1->list[i] != '\0'; i++){
      removeduplicates(mynode1->list, mynode1->list[i], i);
    }
    
    

    return mynode1;

}

void createList2(intarraynode *a, dList *b){
    dList *trav = b;
    dList *prevTrav = NULL;

    int i;

    for(i = 0; i < a->count; i++){
        for(trav = b, prevTrav = NULL; trav != NULL; trav = &(*trav)->next, prevTrav = trav){}

        dList temp = (dList)malloc(sizeof(doublenode));
        temp->data = a->list[i];
        temp->next = NULL;
        temp->prev = *prevTrav;
    }
}