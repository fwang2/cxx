// if build with release
// the assert will be stripped away
// cmake -DCMAKE_BUILD_TYPE=Release

#include <assert.h>
#include <cstdio>

int main() {
    assert(4 == 5);     // run test check

    // compile time check, uncomment the following
    // will generate compile time error

    // static_assert(sizeof(double) == 4, "can't use double of 4");     printf("success!\n");
}
