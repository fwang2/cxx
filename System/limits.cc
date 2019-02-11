#include <climits>
#include <iostream>
int main(void) {
    using namespace std;
    cout << "LONG_MAX =  " << LONG_MAX << endl;
    int x = 2 * 1024 * 1024 * 1024;
    cout << "2 * 1024 * 1024 * 1024 = " << x << endl;
    long y = 2L * 1024L * 1024L * 1024L;
    cout << "2L * 1024L * 1024L * 1024L = " << y << endl;

    return 0;
}
