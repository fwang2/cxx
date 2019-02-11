// demo static variable used in function scope

#include <stdio.h>

void foo() {
    static int x = 10;
    x++;
    printf("%d\n", x);
}

int main() {
    foo();
    foo();
}

