#include <stdio.h>

int main(int argc, char **argv) {
    static long long foo;
    register long long bar;

    foo = 1 << 20;

    bar = -foo;

    printf("foo = %d \n", foo);
    printf("foo = %lld \n", foo);

    printf("bar = %d \n", bar);
    printf("bar = %lld \n", bar);



}

