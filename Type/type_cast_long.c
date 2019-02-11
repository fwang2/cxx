/*
 * the following program shows passing a long to a generic (void *)
 * by casting its value as the address
 *
 * then get the value back by casting (long)
 *
 */

#include <stdio.h>

void test(void * id) {
    long myid;
    myid = (long) id;
    printf("my id is %ld\n", myid);
}


int main() {
    long id = 5;
    test( (void *)id);
}
