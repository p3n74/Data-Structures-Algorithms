#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} *list, node; 

int getSize(){
    int x;
    printf("Enter the number of integers: ");
    scanf("%d", &x);
    return x;
}

void getIntString(int* intString){
    int size = getSize();
    
    intString = (int *)malloc(sizeof(int) *size);
    printf("Enter the integers: ");
    fgets(intString, size * 2 - 1, stdin);
}

int main(){
    
    int size = getSize();
    int* intString;
    
    
    
}