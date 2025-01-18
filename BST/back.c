#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "back.h"

List getTail(List L) {
    while (L != NULL && L->next != NULL)
        L = L->next;
    return L;
}

List partition(List head, List end, List* newHead, List* newEnd) {
    List pivot = end;
    List prev = NULL, cur = head, tail = pivot;

    *newHead = NULL;
    *newEnd = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (*newHead == NULL)
                *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            List temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

List quickSortRecursive(List head, List end) {
    if (!head || head == end)
        return head;

    List newHead = NULL, newEnd = NULL;
    List pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        List temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;
        newHead = quickSortRecursive(newHead, temp);
        temp = getTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecursive(pivot->next, newEnd);

    return newHead;
}

void sortList(List* L) {
    *L = quickSortRecursive(*L, getTail(*L));
}

int genRand(int max, int min){

    // add srand(time(NULL)); to any code calling this helper

    int randomNum = (rand() % max) + min;

    return randomNum; 

}

void initList(List* L){

	*L = NULL;

}

void createList(List *a){
    List *trav;
    for(int i = 5; i > 0; i--){
        for(trav = a; *trav != NULL; trav = &(*trav)->next){}
            node *temp = (node *)malloc(sizeof(node));
            temp->data = genRand(10, 1);
            temp->next = NULL;
            *trav = temp;
    }
}

void printList(List a){
    List trav;

	if(a != NULL){

    printf("\n\t");
    for(trav = a; trav->next != NULL; trav = trav->next){
        printf("%d -> ", trav->data);
    }
    printf("%d", trav->data);
	} else {
		
		printf("\n\tempty\n");
	}
} 

void createRandomListLength(List *a){
    List *trav;
    int length;

    for(length = genRand(10, 5); length > 0; length--){
        for(trav = a; *trav != NULL ; trav = &(*trav)->next){}
            node *temp = (node *)malloc(sizeof(node));
            temp->data = genRand(13,1);
            temp->next = NULL;
            *trav = temp;
    }
}
