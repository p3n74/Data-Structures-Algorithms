#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 10

typedef struct nodeArray{
    int elem[MAX];
    int count;
    struct nodeArray *next;

} *ListArray ;

void populateArray(ListArray *A){

    ListArray *trav;
    int i;
    for(i = 0, trav = A; i < 5; i++){
        (*trav)->elem[i] = (i + 5);
    }
    (*trav)->count = (i);
    (*trav)->next = NULL;
}

void printListArray(ListArray *L){
    
    ListArray *trav;
    int x;

    for(trav = L; (*trav) != NULL; trav = &(*trav)->next){
        for(x = 0; x < ((*trav)->count) - 1; x++){
            printf("%d -> ", (*trav)->elem[x]);
        }
        printf("%d\n", (*trav)->elem[x]);
    }
}

void printInput(int a){
    printf("\nTo be inserted: %d\n", a);
}

void insertSorted(ListArray *A, int b){
    ListArray *trav;
    int x,y;

    for(trav = A; (*trav) != NULL; trav = &(*trav)->next){
        for(x = 0; x <= (*trav)->count && b > (*trav)->elem[x]; x++){}

        if((*trav)->elem[x] >= b){
            if((*trav)->count == (MAX)){
                printf("No more space\n");
            } else {
                for(y = ((*trav)->count) - 1; y >= x; y--){
                    (*trav)->elem[y + 1] = (*trav)->elem[y];
                }
                (*trav)->elem[x] = b;
                (*trav)->count++;
                printInput(b);
                printListArray(A);
            }
        }
    }
}

/*

Assignment

a. insert(x, position, List)
b. delete(p, L)
c. locate(x, L)

*/



int main(){
    srand(time(NULL));

    ListArray L = NULL;

    L = (struct nodeArray*)malloc(sizeof(struct nodeArray));

    populateArray(&L);

    printListArray(&L);

    insertSorted(&L, 9);
    insertSorted(&L, 4);
    insertSorted(&L, 6);
    

    
    



}