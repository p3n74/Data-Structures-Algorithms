#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef struct name{

	char fname[20];
	char lname[20];
} name;

typedef struct student {

	name studname;
	int year;
	char course[5];

} student;

typedef struct studentRecord{

	student studs[5];
	int count;
} studentRecord;


studentRecord* initRecord(){

	studentRecord* temp = (studentRecord*) malloc (sizeof(studentRecord));
	
	return temp;

}

void populateRecord(studentRecord* myRecord){

	student temp;
	strcpy(temp.studname.fname, "ram");
	strcpy(temp.studname.lname, "barria");
	strcpy(temp.course, "BSCS");

	myRecord->studs[0] = temp;

	strcpy(temp.studname.fname, "Mylee");
	strcpy(temp.studname.lname, "Pilapil");
	strcpy(temp.course, "BSCS");

	myRecord->studs[1] = temp;

	strcpy(temp.studname.fname, "Kenneth");
	strcpy(temp.studname.lname, "Cahilog");
	strcpy(temp.course, "BSCS");

	myRecord->studs[2] = temp;
	myRecord->count = 3;

}

void displayData(studentRecord myRecord){

	int i;

	for(i = 0; i < myRecord.count; i++){
		printf("%s %s of %s\n", myRecord.studs[i].studname.fname, myRecord.studs[i].studname.lname, myRecord.studs[i].course);
	}
}


int main(){
	FILE *fp;
	
	studentRecord* myRecord = initRecord();
	populateRecord(myRecord);
	displayData(*myRecord);

	char myfilename[10];
	fgets(myfilename, 10, stdin);

	if((fopen(myfilename, "r") != NULL)){
			fp = fopen(myfilename, "a");
			} else {

			fp = fopen(myfilename, "w");
			}
	// writing to file
	int i;
	fp = fopen(myfilename, "a");

	for(i = 0; i < myRecord->count; i++){
	
		fprintf(fp, "%s %s %s ", myRecord->studs[i].studname.fname, myRecord->studs[i].studname.lname, myRecord->studs[i].course);		



	}


	return 0;
}





















