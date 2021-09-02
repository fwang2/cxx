#include <iostream>
using namespace std;
int main() {
    const int SIZE = 80;
    char buffer[SIZE];
    cout << "Enter a line" << endl;
    // it seems like cin.read won't return until it read 5
    // which is good
    cin.read(buffer, 5);
    cout.write(buffer, cin.gcount() );
    cout << endl;
    return 0;
}

