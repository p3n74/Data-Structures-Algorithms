#ifndef BACK1_H
#define BACK1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct {

    char FName[24], LName[16], MI;

} nametype;

typedef struct {

    unsigned int ID;
    nametype Sname;
    char course[8];
    int yr;

} studrec;

typedef struct node {

    studrec stud;
    struct node *link;

} *qptr, node;

typedef struct {

    qptr front;
    qptr rear;
    int count;

} studQueue;


void populateList(studQueue *Q){

    Q->front = NULL;
    Q->rear = NULL;
    Q->count = 0;

    studrec stud1, stud2, stud3;
    
    stud1.ID = 100;
    stud1.yr = 1;
    strcpy(stud1.Sname.FName, "Joe");
    strcpy(stud1.Sname.LName, "Goldberg");
    strcpy(stud1.course, "BSIT");
    stud1.Sname.MI = 'M';

    stud2.ID = 101;
    stud2.yr = 2;
    strcpy(stud2.Sname.FName, "Karylle");
    strcpy(stud2.Sname.LName, "Bernate");
    strcpy(stud2.course, "BSAM");
    stud2.Sname.MI = 'B';

    stud3.ID = 100;
    stud3.yr = 1;
    strcpy(stud3.Sname.FName, "Andrea");
    strcpy(stud3.Sname.LName, "Golucino");
    strcpy(stud3.course, "BSCS");
    stud3.Sname.MI = 'J';

    qptr stud1temp = (qptr)malloc(sizeof(node));
    stud1temp->stud = stud1;
    stud1temp->link = NULL;

    qptr stud2temp = (qptr)malloc(sizeof(node));
    stud2temp->stud = stud2;
    stud2temp->link = stud1temp;

    qptr stud3temp = (qptr)malloc(sizeof(node));
    stud3temp->stud = stud3;
    stud3temp->link = stud2temp;

    Q->front = stud3temp;
    Q->rear = stud1temp;
    Q->count = 3;

}

void printRecords(studQueue Q){

    qptr trav;
    for(trav = Q.front; trav != NULL; trav = Q.front->link){
        printf("Name: %d %s %c %s of %s-%d\n", trav->stud.ID, trav->stud.Sname.FName, trav->stud.Sname.MI, trav->stud.Sname.LName, trav->stud.course, trav->stud.yr);
    }


}

#endif