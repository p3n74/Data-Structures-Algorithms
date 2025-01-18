#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "virtualheapfunc.c"

void printMenu();
int intscanner();
void printSysInfo(virtualHeap* VH);


int main (){
    // Initialize randomizer
    srand(time(NULL));

    // allocate the virtual heap
    virtualHeap* VH = (virtualHeap *)malloc(sizeof(virtualHeap));

    int mode = 0;

    int head = -1;

    int errorCode = 0;

    initHeap(VH);
    //populateListRandom(VH);

    while(mode != 1){

        system("clear");
        printSysInfo(VH);
        printList(VH, head);
        printMenu();

        printError(&errorCode);

        mode = intscanner();
        if(mode == 2){
            errorCode = push(VH, &head);
        } else if (mode == 3){
            errorCode = pop(VH, &head);
        }
    }




    return 0;
}





void printMenu(){
   
    printf("\n\t Menu \n");
    printf("[1] Exit\n");

    printf("\n Stack Functions: \n");

    printf("[2] Push\n");
    printf("[3] Pop\n");

    printf("\n Queue Functions: \n");
    printf("[4] Enqueue\n");
    printf("[5] Dequeue\n");
}


