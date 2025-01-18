#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "back.c"



void initHeap(virtualHeap *VH){

    int x;
    VH->avail = 0;

    for(x = 0; x < MAX - 1; x++){
        VH->nodes[x].next = x + 1;
    }
    VH->nodes[MAX - 1].next = -1;

}

int allocSpace(virtualHeap *VH){

    int result = VH->avail;
    if(result != -1){
        VH->avail = VH->nodes[result].next;
    }

    return result;
}

void deallocSpace(virtualHeap *VH, int index){

    int *trav;
    for(trav = &(VH->avail); *trav != -1; trav = &(VH->nodes[*trav].next)){}

    *trav = index; 
}

void populateListRandom(virtualHeap *VH){

    int temp;
    for(temp = VH->avail; VH->nodes[temp].next != -1; temp = VH->nodes[temp].next){
        VH->nodes[temp].data = genRand(20,1);
    }
}


void printList(virtualHeap* VH, int head){

    int temp;

    if(head == -1){
        printf("No list entered/List Empty\n");
    } else {
        for(temp = head; temp != -1 && VH->nodes[temp].next != -1; temp = VH->nodes[temp].next){
            printf("%d ->", VH->nodes[temp].data);
        }
        printf("%d\n", VH->nodes[temp].data);
    }
}

int countAvail(virtualHeap* VH){

    int temp, availCount;

    for(availCount = 0, temp = VH->avail; temp != -1; temp = VH->nodes[temp].next, availCount++){}

    return availCount;
}


int push(virtualHeap* VH, int* head){

    
    

    int runCode = 0;

        int space = allocSpace(VH);
        int *trav;

        if(space != -1){
            int input;
            
            printf("Enter Value to input: ");
            input = intscanner();

            VH->nodes[space].data = input;
            VH->nodes[space].next = -1;

            for(trav = head; *trav != -1; trav = &(VH->nodes[*trav].next)){}

            *trav = space;
    } else {
        runCode = 1;
    }

    return runCode;
}

int pop(virtualHeap* VH, int *head){

    int* trav;
    int result = 0;

    if(*head == -1){
        result = 2;
    } else {
        for(trav = head; *trav != -1 && VH->nodes[*trav].next != -1; trav = &(VH->nodes[*trav].next)){}

        deallocSpace(VH, VH->nodes[*trav].next);
        *trav = -1;
    }

        return result;

}

void printSysInfo(virtualHeap* VH){

    int availableNodes = countAvail(VH);
    
    printf("Available Nodes: ");
    printf("%d\n\n", availableNodes);
}