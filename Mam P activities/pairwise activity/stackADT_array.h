#ifndef STACKADTARRAY_H
#define STACKADTARRAY_H

#include <stdbool.h>

#define MAX 10

typedef struct {
    char data[MAX];
    int top;
} stack;


bool empty(stack* stack_main){
    
    return (stack_main->top == -1)? true : false; 
}

bool full(stack* stack_main){
    return (stack_main->top >= MAX)? true : false;
}

void initialize(stack** stack_main){

    *stack_main = (stack*)malloc(sizeof(stack));

    (*stack_main)->top = -1;
}

void makeNull(stack* stack_main){

    stack_main->top = -1;
}



void push(stack** stack_main, char input){
    if(!full(*stack_main)){
        (*stack_main)->top++;
        (*stack_main)->data[(*stack_main)->top] = input;
    }
}

char pop(stack** stack_main){

    char temp = 0;

    if(!empty(*stack_main)){
        temp = (*stack_main)->data[(*stack_main)->top--];
    }

    return temp;
}

void reverseCase(char* elem) {
    if ((*elem >= 'a' && *elem <= 'z') || (*elem >= 'A' && *elem <= 'Z'))
        *elem ^= 32;
}

void revtop(stack** stack_main){
    if(!empty(*stack_main))
        reverseCase(&((*stack_main)->data[(*stack_main)->top]));
}

char top(stack** stack_main){
    char temp = 0;
    if(!empty(*stack_main)){
        temp = (*stack_main)->data[(*stack_main)->top];
    }

    return temp;
}



#endif
