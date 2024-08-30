#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "back.c"
#include "back.h"

void initHeap(virtualHeap *VH);
void populateListRandom(virtualHeap *VH);
void printHeap(virtualHeap *VH, int head);

int main (){
    // Initialize randomizer

    srand(time(NULL));

    // allocate the virtual heap

    virtualHeap* VH = (virtualHeap *)malloc(sizeof(virtualHeap));

    initHeap(VH);
    populateListRandom(VH);
    printHeap(VH, -1);


    return 0;
}

void initHeap(virtualHeap *VH){

    int x;
    VH->avail = 0;

    for(x = 0; x < MAX - 1; x++){
        VH->nodes[x].next = x + 1;
    }
    VH->nodes[MAX - 1].next = -1;

}

void populateListRandom(virtualHeap *VH){

    int temp;
    for(temp = VH->avail; VH->nodes[temp].next != -1; temp = VH->nodes[temp].next){
        VH->nodes[temp].data = genRand(20,1);
    }
}

void printHeap(virtualHeap *VH, int head){

    int temp, ahead;

    printf("Available Nodes: \n");
    for(temp = VH->avail, ahead = VH->nodes[temp].next; VH->nodes[temp].next != -1 && VH->nodes[ahead].next != -1; temp = VH->nodes[temp].next, ahead = VH->nodes[ahead].next){
        printf("%d -> ", VH->nodes[temp].data);
    }
    printf("%d\n", VH->nodes[temp++].data);

    if(head == -1){
        printf("No list entered\n");
    } else {
        for(temp = VH->avail, ahead = VH->nodes[temp].next; VH->nodes[temp].next != -1 && VH->nodes[ahead].next != -1; temp = VH->nodes[temp].next, ahead = VH->nodes[ahead].next){
        printf("%d ->", VH->nodes[temp].data);
    }
    }
}