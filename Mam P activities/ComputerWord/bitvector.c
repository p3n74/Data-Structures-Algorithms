#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX (sizeof(unsigned char) * 8)

// unsigned char is 1 byte so its now 8 bits

typedef unsigned char Set;

void init(Set *A);
void display(Set A);
void insert(Set *A, int place);
void delete(Set *A, int place);
bool member(Set A, int place);
void isMember(Set A, int place);
void displaySetR(Set A);
void displaySetL(Set A);

int main(){

    Set A;
    init(&A);
    insert(&A, 8);
    insert(&A, 4);
    insert(&A, 3);
    insert(&A, 1);
    //delete(&A, 8);
    display(A);

    isMember(A, 1);
    displaySetR(A);
    displaySetL(A);

}

void displaySetR(Set A){

    int i;
    unsigned char mask = 1;
    printf("Set form MSB to LSB: {");
    for(i = (int)MAX - 1;
        i > 0;
        i--)
    {
        mask = 1 << (i);
        if((A & mask) == mask){
            printf("%d ", i);
        }
    }
    printf("}\n");

}

void displaySetL(Set A){

    int i;
    unsigned char mask = 1;
    printf("Set form LSB to MSB: {");
    for(i = 1;
        i < (int)MAX;
        i++)
    {
        mask = 1 << (i);
        if((A & mask) == mask){
            printf("%d ", i);
        }
    }
    printf("}\n");

}

void isMember(Set A, int place){
    printf("\n Is the %dth digit present?: ", place);
    (member(A, place))? printf("Yes\n") : printf("No\n");
}

bool member(Set A, int place){
    Set mask = 1;

    mask = mask << (place - 1);

    return ((A & mask) == mask)? true : false;
}

void init(Set *A){

    *A = 0;

}

void display(Set A){

    unsigned char mask;
    int res = 0;

    printf("Bit Vector is: ");
    for(
        mask = 1 << (MAX - 1);
        mask > 0;
        mask = mask >> 1 
    ) {

        res = ((A & mask) == mask)? 1 : 0;
        printf("%d", res);

    }
    printf("\n");
}

void insert(Set *A, int place){

    if(place <= (int)MAX){
        *A |= 1 << (place -1);
    }

}

void delete(Set *A, int place){

    if(place <= (int)MAX){
        *A &= ~(1 << (place - 1));
    }

}