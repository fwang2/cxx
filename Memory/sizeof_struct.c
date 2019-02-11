/**
 * demostrate when you use a zero-length array
 * such as "name" in a structure def, the sizeof
 * will not include any len from it
 *
 * Running results:
 * struct size 1 = 16
 * struct size 2 = 24
 *
 * This behavior stays the same in C++
 */

#include <stdio.h>
#include <stdint.h>

struct inotify_event {
    int wd;
    uint32_t mask;
    uint32_t cookie;
    uint32_t len;
    char name[];
};


struct inotify_event2 {
    int wd;
    uint32_t mask;
    uint32_t cookie;
    uint32_t len;
    char * name;
};

int main(void) {
    size_t i = sizeof(struct inotify_event);
    printf("struct size 1 = %zd\n", i);
    size_t j = sizeof(struct inotify_event2);
    printf("struct size 2 = %zd\n", j);
}

