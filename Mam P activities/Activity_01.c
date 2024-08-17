#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} *List, node;

List initListWithHeader();
void initListWithoutheader(List *a);
void insertLast(int elem, List *a);
void insertLastLookahead(int elem, List a);

void deletefirst(int elem, List *a);
void deletefirstlookahead(int elem, List a);


int main(){

    List list1;
    List list2;

    list1 = initListWithHeader();
    initListWithoutheader(&list2);

    for(int i = 5; i > 0; i--){
        insertLast(i, &list2);
    
    }
    for(int i = 5; i > 0; i--){
       
        insertLastLookahead(i, list1);
    }

    deletefirst(3, &list2);
    deletefirst(1, &list2);
    deletefirstlookahead(3, list1);
    deletefirstlookahead(1, list1);

}

node *initListWithHeader(){
    node *temp = (node *)malloc(sizeof(node));

    temp->data = 0;
    temp->next = NULL;

    return temp;
}

void initListWithoutheader(List *a){
    *a = NULL;
}

void insertLast(int elem, List *a){
    List *trav;
    for(trav = a; *trav != NULL; trav = &(*trav)->next);

    // create node
    node *temp = (node *)malloc(sizeof(node));
    temp->data = elem;
    temp->next = NULL;

    *trav = temp;
}

void insertLastLookahead(int elem, List a){

    List trav = a;
    for(; trav->next != NULL; trav = trav->next){}

    // create node
    node *temp = (node *)malloc(sizeof(node));
    temp->data = elem;
    temp->next = NULL;

    trav->next = temp;
}

void deletefirst(int elem, List *a){
    List *trav;
    for(trav = a; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->next){}
    //house keeping
    List temp = *trav;
    (*trav) = (*trav)->next;
    free(temp);
}

void deletefirstlookahead(int elem, List a){
    List trav = a;
    for(; trav && trav->next->data != elem; trav = trav->next){}
    // house keeping
    if(trav){
        List temp = trav->next;
        if(trav->next->next){
            trav->next = trav->next->next;
            
        } else {
            trav->next = NULL;
        }
        free(temp);
        
    }
}