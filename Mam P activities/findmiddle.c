#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "back.c"
#include "back.h"

void findMiddle(List a){
    if(a == NULL){
        printf("The list is empty");
    } else {
        int middleData = -1;
        int loops = 0;

        List slow, fast;

        for(fast = a, slow = a; fast != NULL && fast->next != NULL; slow = slow->next, fast = fast->next->next, loops++){}
        middleData = slow->data;

        printf("%d, loops: %d", middleData, loops);
    }
}

int main(){

    srand(time(NULL));

    List L = NULL;

    createRandomListLength(&L);
    printList(L);

    printf("\n");

    printf("\tThe middle is: ");
    findMiddle(L);



}