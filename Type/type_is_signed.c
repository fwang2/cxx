#include <stdio.h>

#define IS_SIGNED(x) ( x>=0 && ~x >=0 ) 
int main() 
{
    int a = 0;
    unsigned int b = 2;

    if IS_SIGNED(a) {
        printf("a = %d is signed \n", a);
    } else {
        printf("a = %d is unsigned \n", a);
    }

    if IS_SIGNED(b) {
        printf("b = %d is signed \n", b);
    } else {
        printf("b = %d is unsigned \n", b);
    }


    return 0;
}

