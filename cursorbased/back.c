#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "back.h"

int genRand(int max, int min){

    // add srand(time(NULL)); to any code calling this helper

    int randomNum = (rand() % max) + min;

    return randomNum; 

}

