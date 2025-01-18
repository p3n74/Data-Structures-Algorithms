#include <stdio.h>

int main(){

    int i, result = 0;
    int nums[] = {};
    int numsSize = 0;

    for(i = 0; i < numsSize;){
        result ^= nums[i++];
    }

    printf("%d", result);
    return result;

}