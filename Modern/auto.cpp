
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
    map<int, string> msg;
    msg[0] = "hello";
    msg[1] = "world";

    /// method 1
    map<int,string>::const_iterator it = msg.begin();
    while ( it != msg.end() ) {
        cout << it->first << "=" << it->second << "\n";
        ++it;
    }
    /// method 2, auto type deduction

    auto ait = msg.begin();
    while ( ait != msg.end() ) {
        cout << ait->first << "=" << ait->second << "\n";
        ++ait;
    }

    return 0;
}

