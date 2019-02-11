#include <iostream>
#include <boost/format.hpp>
using namespace std;
using boost::format;

int main(void) {
    int y = 100;
    cout << format("100(d) = %-08d \n") % y;
    cout << format("100(x) = 0x%08x \n") % y;
}

