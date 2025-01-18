#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "back.c"
#include "back.h"





int main(){

    srand(time(NULL));

    dList Mylist = NULL;

    intarraynode *mynode1 = genRandListUnique();

    
    createList2(mynode1, &Mylist);
    int i;
    for(i = 0; i < 5; i++){
        printf("%d ", mynode1->list[i]);
    }

    printf("\n");
    //for(trav = &Mylist , i = 0; i < 5; i++, trav = &(*trav)->next){
      //  printf("%d ", (*trav)->data);
    //}

    return 0;
}

