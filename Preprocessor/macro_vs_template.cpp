// side-effects.cpp by Bill Weinman <http://bw.org/>
// updated 2018-10-11
#include <cstdio>
#include <cstdlib>
#include <ctime>

namespace bw {
    static unsigned _x = 0;
    class R {
    public:
        unsigned operator()() {
            srand(_x + (unsigned) time(0));
            return (_x += rand()) % 100;
        }
    };
}

#define TIMES(a, b) (a * b)
#define MAX(a, b) (a > b ? a : b)


// C++ typesafe solution to replace macros
template<typename T>
void print_max(T a, T b) {
    printf("max of %d and %d is %d\n", a, b, (a > b ? a : b));
}

int main()
{
    // THIS WORKS
    printf("macro returns %d\n", TIMES(5, 25));

    // THIS WILL NOT WORK
    bw::R bob;
    bw::R fred;
    printf("max of %d and %d is %d\n", bob(), fred(), MAX(bob(), fred()) );

    // THIS WILL WORK
    print_max(bob(), fred());
    return 0;
}
