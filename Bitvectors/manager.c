#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sets.h"


int main(){

    Set* A = (Set*)malloc(sizeof(Set));

    init(A);
    *A = (Set)123;
    display(A);
    printf("\n");
    for(int i = 7; i >= 0; i--){
        if(member(A, i)){
            printf("member\n");
        } else {
            printf("no\n");
        }
    }
    delete(A, 4);
    display(A);

    insert(A, 3);
    printf("\n");
    display(A);

    return 0;
}