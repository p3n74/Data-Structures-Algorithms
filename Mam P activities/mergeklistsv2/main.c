#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} *list;

list* createlist(){
    int i;

    list head = (list)malloc(sizeof(struct node));
    head->data = 0;
    head->next = NULL;

    list trav = head->next;

    for(i = 0; i < 4; i++){
        list temp = (list)malloc(sizeof(struct node));
        temp->data = 0;
        temp->next = NULL;

        trav->next = temp;
        trav = trav->next;
    }

    return &head;
}

int main(){

    list *array[10];

    for(int i = 0; i < 10; i++){
        array[i] = createlist();
        
    }

    return 0;
}




