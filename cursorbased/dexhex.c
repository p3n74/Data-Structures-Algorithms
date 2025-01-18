#include <stdio.h>

int main (){
    int x,y;
    printf("Enter hex 1 value: ");
    scanf("%X", &x);
    printf("Enter hex 2 value: ");
    scanf("%X", &y);
    printf("x = %d, y = %d, x * y = %d , %X", x,y, x - y, x - y);
}