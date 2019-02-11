// demo: a way to decide how much malloc () you can make
// question: will it work?


#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    char c;
    char *high = &c;
    unsigned int diff;
    char *low = (char *) malloc(sizeof(char));

    printf("high = %p \n", high);
    printf("low  = %p \n", low);
    diff = high - low;
    printf("malloc max = %u bytes \n", diff);
    printf("           = %u MiB bytes\n", diff >> 20);
}

