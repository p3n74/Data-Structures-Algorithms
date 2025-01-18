#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Include this for strcpy

#define MAX 10

typedef struct {
    char fname[MAX];
    char lname[MAX];
} name;

typedef struct {
    name studentName;
    int yearLevel;
    char course[MAX];
} student;

int main() {
    student stud1;

    char tempFname[MAX] = "Gran";
    char tempLname[MAX] = "Sabandal";
    char tempCourse[MAX] = "BSIT";

    strcpy(stud1.studentName.fname, tempFname);
    strcpy(stud1.studentName.lname, tempLname);
    strcpy(stud1.course, tempCourse);
    
    stud1.yearLevel = 1;

    printf("Name: %s %s\n", stud1.studentName.fname, stud1.studentName.lname);
    printf("Course: %s\n", stud1.course);
    printf("Year Level: %d\n", stud1.yearLevel);

    return 0;
}
