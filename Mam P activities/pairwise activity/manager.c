#include <stdio.h>
#include <stdlib.h>


// just pick the one u wanna use

//#include "stackADT_array.h"
#include "stackADT_linkedList.h"


//old

/*
void displayStack(stack* stack_main){

    if(empty(stack_main)){
        printf("Empty: \n");
    } else {
        stack* trav;
        for(trav = stack_main; trav != NULL; trav = trav->next){
            printf("%c ", trav->data);
        }
        printf("\n");
    }
    

} */




void displayStack(stack** stack_main){

    if(!empty((*stack_main))){
        stack* tempStack;
        char temp;

        initialize(&tempStack);

        while(!empty((*stack_main))){

            temp = top(stack_main);
            pop(stack_main);
            push(&tempStack, temp);
        }
        //printing
        
        while(!empty(tempStack)){
            temp = top(&tempStack);
            printf("%c ", temp);
            pop(&tempStack);
            push(stack_main, temp);
        }
        printf("\n");
    } else {

        printf("Empty: \n");

    }
    

}


int main() {
    int choice = 0;
    char temp;
    stack* stack_main;

    initialize(&stack_main);

    while (choice != 4) {
        system("clear");
        displayStack(&stack_main);
        printf("Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        if(choice == 1){
            printf("Enter a Character: ");
            scanf(" %c", &temp);
            push(&stack_main, temp);

        } else if (choice == 2){
            temp = pop(&stack_main);
        } else if (choice == 3){
            // idk what top supposed to do, just made it flip
            revtop(&stack_main);
        }
        system("clear");
        
        
    }

    return 0;
}

