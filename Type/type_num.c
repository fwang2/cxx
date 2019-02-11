#include <stdio.h>
#define NUM1    010
#define NUM2    0x010
#define NUM3    100

int main(int argc, char**argv)
{
    printf("010 = %d\n", NUM1);
    printf("0x010 = %d\n", NUM2);
    printf("100 = %d\n", NUM3);
    return 0;
}

