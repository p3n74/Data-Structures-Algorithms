#ifndef STACKADTLINKEDLIST_H
#define STACKADTLINKEDLIST_H

#include <stdbool.h>


typedef struct node{
    char data;
    struct node* next;
} stack, node;


bool empty(stack* stack_main){
    
    return (stack_main == NULL)? true : false; 
}

// bool full(stack stack_main){
//     return (stack_main.top >= MAX)? true : false;
// }


void initialize(stack** stack_main){

    *stack_main = NULL;
}



void push(stack** stack_main, char input){
    stack** trav;
    for(trav = stack_main; *trav != NULL; trav = &(*trav)->next){}
    stack* temp = (stack*)malloc(sizeof(node));
    temp->data = input;
    temp->next = NULL;

    *trav = temp;
}

char pop(stack** stack_main){
    char result = 0;

    if(!empty(*stack_main)){
        
        
        stack** trav;
        for(trav = stack_main; *trav != NULL && (*trav)->next != NULL; trav = &(*trav)->next){}
        
        stack* temp = (*trav)->next;
        result = (*trav)->data;
        *trav = NULL;
        free(temp);
    }

    return result;
}

void reverseCase(char* elem) {
    if ((*elem >= 'a' && *elem <= 'z') || (*elem >= 'A' && *elem <= 'Z'))
        *elem ^= 32;
}

void revtop(stack** stack_main){
    if(!empty(*stack_main)){
        stack** trav;
        for(trav = stack_main; *trav != NULL && (*trav)->next != NULL; trav = &(*trav)->next){}
        reverseCase(&((*trav)->data));
    }
        
}

char top(stack** stack_main){
    char result = 0;
    if(!empty(*stack_main)){
        stack** trav;
        for(trav = stack_main; *trav != NULL && (*trav)->next != NULL; trav = &(*trav)->next){}
        result = (*trav)->data;
    }

    return result;
}







#endif
