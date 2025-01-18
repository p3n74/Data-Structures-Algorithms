#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




/*
write the code of the function isAscendingID(). Given the queue, the fucntion will return TRUE if the elements from
front  to rear are arrange in ascending __ORDER_BIG_ENDIAN__

Constraints: 
1. Function is ascending cannot call user defined functions
2. There should be 1 return statement __DARWIN_ONLY_64_BIT_INO_T

*/


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

void populateList(studQueue *Q);
void printRecords(studQueue *Q);
studQueue removeCourse(studQueue *Q, char course[]);
bool isAscending(studQueue *Q);

int main(){

studQueue studs;
populateList(&studs);
printRecords(&studs);
//studQueue appMath = removeCourse(&studs, "BSAM");


// printRecords(studs);
// printRecords(appMath);

if(isAscending(&studs) == true){
    printf("\nyes\n");
} else {
    printf("\nno\n");
}
printRecords(&studs);

}

bool isAscending(studQueue *Q){
    bool result = true;
    int i;
    for(i = 0; i < Q->count; i++){

        if(Q->front->stud.ID > Q->front->link->stud.ID && i < Q->count -1){
            result = false;
        }

        Q->rear->link = Q->front;
        Q->rear = Q->front;
        Q->front = Q->front->link;
        Q->rear->link = NULL;

    }

    

      


    return result;

}

studQueue removeCourse(studQueue *Q, char course[]){

    studQueue result;

    // Initialize Result

    result.count = 0;
    result.front = NULL;
    result.rear = NULL;


    qptr* frontP;

    qptr temp = NULL;

    int i;
    for(i = 0, frontP = &(Q->front); i < Q->count; i++){

        if( strcmp((*frontP)->stud.course, course) == 0){
            temp = (*frontP);
            *frontP = (*frontP)->link;
            temp->link = NULL;

            if(result.front == NULL && result.rear == NULL){
                result.front = temp;
                result.rear = temp;
            } else {
                temp->link = result.front;
                result.front = temp;
            }
            
        }   

        // The rear of the Queue will now point to the front

        Q->rear->link = Q->front;

        // The rear pointer will now point to the front

        Q->rear = Q->front;

        // The front pointer will now point to the next node

        Q->front = Q->front->link;

        // The rear node, that is currently attaced to the front will now be detached and point to NULL

        Q->rear->link = NULL;
        
    }

    return result;

}

void populateList(studQueue *Q){

    Q->front = NULL;
    Q->rear = NULL;
    Q->count = 0;

    studrec stud1, stud2, stud3;
    
    stud1.ID = 102;
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
    strcpy(stud3.Sname.FName, "Christine");
    strcpy(stud3.Sname.LName, "Peña");
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

void printRecords(studQueue *Q){

    int i;
    for(i = 0; i < Q->count; i++){
        printf("Current Address: %X, Next Address: %X\n", Q->front, Q->front->link);
        printf("Name: %d %s %c %s ", Q->front->stud.ID, Q->front->stud.Sname.FName, Q->front->stud.Sname.MI, Q->front->stud.Sname.LName);
        printf("of %s-%d\n", Q->front->stud.course, Q->front->stud.yr);

        Q->rear->link = Q->front;
        Q->rear = Q->front;
        Q->front = Q->front->link;
        Q->rear->link = NULL;

    }

    printf("\n front: %X - > %X, rear: %X - > %X \n", Q->front, Q->front->link, Q->rear, Q->rear->link);

   

    // qptr trav;
    // for(trav = Q.front; trav != NULL; trav = trav->link){
    //     printf("Current Address: %X, Next Address: %X\n", trav, trav->link);
    //     printf("Name: %d %s %c %s of %s-%d\n", trav->stud.ID, trav->stud.Sname.FName, trav->stud.Sname.MI, trav->stud.Sname.LName, trav->stud.course, trav->stud.yr);
    // }

    printf("\n");


}