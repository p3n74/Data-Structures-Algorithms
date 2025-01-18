#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "back.h"


int main(){

    studList rawList;
    studDict studIDdict;
    initStudlist(&rawList);
    populateStudlist(&rawList);

    //unsigned char ID = 65;
    //printBitPattern(ID);

    printList(rawList);
    printList(rawList);


    initDict(studIDdict);
    dictify(studIDdict, &rawList);
    printDict(studIDdict);

    
}


