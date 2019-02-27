#include <sstream>
#include <iostream>
using namespace std;

int main(void) {
    char c;
    string msg("hello");
    istringstream iss(msg);
    unsigned int i = 0;
    while (i < 10) {
        iss >> c;
        cout << c;
        i++;
    }
    cout << endl;
    return 0;
}

