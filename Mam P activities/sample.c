#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "back.c"
#include "back.h"

int main(){

    srand(time(NULL));

    List L = NULL;

    createList(&L);
    printList(L);

}