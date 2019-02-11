#include <cstdio>
#include <iostream>
#include <boost/format.hpp>

struct bits_t {
    unsigned int io: 1;
    int co;
};

int main(void) {

    using std::cout;
    using boost::format;

    bits_t b; b.io = 1; b.co = 2;

    printf("io = %d \n", b.io); // Okay
    cout << format("co = %d \n") % b.co;  // Okay
    cout << format("io = %d \n") % b.io;  // Not Okay
    return 0;

}

