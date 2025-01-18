#ifndef BACK_H
#define BACK_H

#include <stdlib.h>
#include <string.h>

typedef struct {

    char FName [20];
    char LName [30];

} name;

typedef struct {

    unsigned char code;
    char name[5];

} course;

typedef struct {

    unsigned char ID;
    name studname;
    course studCourse;
    int year;

} studentInfo;

typedef struct node {

    studentInfo stud;
    struct node* next;

} *studptr, node;


typedef struct {

    studptr front;
    studptr rear;
    int count;

} studList;

typedef studList studDict[8];

int hash(unsigned char A){
    int i;
    unsigned char mask;
    for(
        i = 0, mask = 1 << 7;
        mask > 0 && ((A & mask) == 0);
        i++, mask >>= 1
    ){}

    return i;
}

void initStudlist(studList *A){

    A->front = NULL;
    A->rear = NULL;
    A->count = 0;

}

void printBitPattern(unsigned char A){

    unsigned char mask;
    int res = 0;

    //printf("Bit Vector is: ");
    for(
        mask = 1 << (8 - 1);
        mask > 0;
        mask = mask >> 1 
    ) {

        res = ((A & mask) == mask)? 1 : 0;
        printf("%d", res);

    }

}

void enqueue(studptr *rear, studentInfo newStud){

    studptr temp = (studptr) malloc(sizeof(node));
    temp->stud = newStud;
    temp->next = NULL;

    if(*rear != NULL){
        (*rear)->next = temp;
    }
    *rear = temp;

    
}



// void printList(studList A){

//     studptr current = A.front;
//     int i = 1;

//     while(current != NULL){

//         printf("[%i] ", i++);
//         printBitPattern(current->stud.ID);
//         printf(" %s %s-%d", current->stud.studname.LName, current->stud.studCourse.name, current->stud.year);
//         printf(" Hash: %d\n", hash(current->stud.ID));

//         current = current->next;  // Move to the next node
//     }
//     printf("\n");
// }

void printList(studList A){

    int i;
    for(i = 1; i <= A.count; i++){

            printf("[%i] ", i);
            printBitPattern(A.front->stud.ID);
            printf(" %s %s-%d", A.front->stud.studname.LName, A.front->stud.studCourse.name, A.front->stud.year);
            printf(" Hash: %d\n", hash(A.front->stud.ID));

        
        A.rear->next = A.front;
        A.rear = A.front;
        A.front = A.front->next;
        A.rear->next = NULL;

    }
    printf("\n");

}

void initDict(studDict A){

    int i;
    for(i = 0; i < 8; i++){
        A[i].front = NULL;
        A[i].rear = NULL;
        A[i].count = 0;
    }

}

void transfer(studptr *rear, studptr B){
    if(*rear != NULL){
        (*rear)->next = B;
    }

    (*rear) = B;
    (*rear)->next = NULL;

}

void dictify(studDict A, studList *B){

    // foreach
    int i, hashRes;
    studptr temp;
    for(i = 1; i <= B->count; i++){
        hashRes = hash(B->front->stud.ID);

        temp = B->front;
        B->front = B->front->next;


        if(A[hashRes].front == NULL){
            A[hashRes].front = temp;
        }

        transfer(&(A[hashRes].rear), temp);
        A[hashRes].count++;
        
    }

    B->front = B->rear = NULL;
    B->count = 0;

}

void createDict(studList A){

    int i;
    for(i = 1; i <= A.count; i++){




        A.rear->next = A.front;
        A.rear = A.front;
        A.front = A.front->next;
        A.rear->next = NULL;
    }

}

void printDict(studDict A){

    int i;
    for(
        i = 0;
        i < 8;
        i++
    ){
        if(A[i].front == NULL){

            printf("list [%i] is empty \n", i);

        } else {
            printf("List [%i]:\n", i);
            printList(A[i]);
        }
    }
}

// populate list with data

void populateStudlist(studList *A){

    studentInfo temp1;
    temp1.ID = 1;
    strcpy(temp1.studname.FName, "Fabiola");
    strcpy(temp1.studname.LName, "Villanueva");
    strcpy(temp1.studCourse.name, "BSCS");
    temp1.studCourse.code = 1;
    temp1.year = 3;
    enqueue(&(A->rear), temp1);
    A->count++;
    A->front = A->rear; // because it's the first element

    // Student 2
    studentInfo temp2;
    temp2.ID = 2;
    strcpy(temp2.studname.FName, "Lorenzo");
    strcpy(temp2.studname.LName, "Delacruz");
    strcpy(temp2.studCourse.name, "BSIT");
    temp2.studCourse.code = 2;
    temp2.year = 2;
    enqueue(&(A->rear), temp2);
    A->count++;

    //Student 3
    studentInfo temp3;
    temp3.ID = 3;
    strcpy(temp3.studname.FName, "Andrea");
    strcpy(temp3.studname.LName, "Mendoza");
    strcpy(temp3.studCourse.name, "BSIS");
    temp3.studCourse.code = 3;
    temp3.year = 4;
    enqueue(&(A->rear), temp3);
    A->count++;

    // Student 4
    studentInfo temp4;
    temp4.ID = 3;
    strcpy(temp4.studname.FName, "Diego");
    strcpy(temp4.studname.LName, "Santos");
    strcpy(temp4.studCourse.name, "BSAM");
    temp4.studCourse.code = 4;
    temp4.year = 1;
    enqueue(&(A->rear), temp4);
    A->count++;

    // Student 5
    studentInfo temp5;
    temp5.ID = 5;
    strcpy(temp5.studname.FName, "Samantha");
    strcpy(temp5.studname.LName, "Reyes");
    strcpy(temp5.studCourse.name, "BSCS");
    temp5.studCourse.code = 1;
    temp5.year = 2;
    enqueue(&(A->rear), temp5);
    A->count++;

    // Student 6
    studentInfo temp6;
    temp6.ID = 6;
    strcpy(temp6.studname.FName, "Ricardo");
    strcpy(temp6.studname.LName, "Garcia");
    strcpy(temp6.studCourse.name, "BSIT");
    temp6.studCourse.code = 2;
    temp6.year = 3;
    enqueue(&(A->rear), temp6);
    A->count++;

    // Student 7
    studentInfo temp7;
    temp7.ID = 7;
    strcpy(temp7.studname.FName, "Isabella");
    strcpy(temp7.studname.LName, "Torres");
    strcpy(temp7.studCourse.name, "BSIS");
    temp7.studCourse.code = 3;
    temp7.year = 1;
    enqueue(&(A->rear), temp7);
    A->count++;

    // Student 8
    studentInfo temp8;
    temp8.ID = 8;
    strcpy(temp8.studname.FName, "Marco");
    strcpy(temp8.studname.LName, "Cruz");
    strcpy(temp8.studCourse.name, "BSAM");
    temp8.studCourse.code = 4;
    temp8.year = 4;
    enqueue(&(A->rear), temp8);
    A->count++;

    // Student 9
    studentInfo temp9;
    temp9.ID = 9;
    strcpy(temp9.studname.FName, "Natalie");
    strcpy(temp9.studname.LName, "Bautista");
    strcpy(temp9.studCourse.name, "BSCS");
    temp9.studCourse.code = 1;
    temp9.year = 1;
    enqueue(&(A->rear), temp9);
    A->count++;

    // Student 10
    studentInfo temp10;
    temp10.ID = 10;
    strcpy(temp10.studname.FName, "Carlos");
    strcpy(temp10.studname.LName, "Lopez");
    strcpy(temp10.studCourse.name, "BSIT");
    temp10.studCourse.code = 2;
    temp10.year = 4;
    enqueue(&(A->rear), temp10);
    A->count++;
}


#endif