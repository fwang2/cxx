/*
    this is demo rvalue ref
*/

#include <iostream>
using namespace std;
void printInt(int& i) {
    cout << "lvalue reference" << '\n';
}

void printInt(int&& i) {
    cout << "rvalue reference" << '\n';
}

int main() {
    int a = 5; // a is lvalue
    printInt(a); // calling printInt(int&)
    printInt(6); // calling printInt(int&&)
}