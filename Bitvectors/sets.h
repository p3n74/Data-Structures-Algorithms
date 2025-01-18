#ifndef SETS_H
#define SETS_H

typedef unsigned char Set;

void init(Set* A){

    *A = 0;
}

void display(Set* A){

    unsigned char mask;
    int res = 0;

    for(
        mask = 1 << (sizeof(char) * 8 - 1);
        mask > 0;
        mask = mask >> 1
    ){  
        res = ((*A & mask) == mask)? 1 : 0;
        printf("%d ", res);
    }
}

bool member(Set* A, int place){
    bool result = false;
    if(place < 8){
        result = ((*A & ((1 << place))) == ((1 << place)))? true : false;
    }

    return result;
}

void delete(Set* A, int place){
    if(place < 8){
        if((*A & ((1 << place))) == ((1 << place))){
            int subtractor = (1 << place);
            int borrow;
            while(subtractor != 0){
                borrow = (~(*A)) & subtractor;

                *A = *A ^ subtractor;

                subtractor = borrow << 1;
            }
        }
        
    }
}

void insert(Set* A, int place){
    if(place < 8){
        (*A) |= 1 << place;
    }
}


#endif