// vector-test.cpp by Bill Weinman <http://bw.org/>
// version of 2018-11-11

// this demonstrate how to call "std::move()" directly, 
// to move a object from one to another.

#include <cstdio>
#include <vector>
#include <string>
#include <utility>
using namespace std;

void message(const string & s) {
    puts(s.c_str());
    fflush(stdout);
}

void disp_t(vector<string> & v) {
    if(v.empty()) {
        puts("[empty]");
    } else {
        for( string s : v ) printf("%s ", s.c_str());
        puts("");
    }
    fflush(stdout);
}

template <typename T>
void swap(T & a, T & b) {
    message("swap()");
    T _tmp(std::move(a));
    a = std::move(b);
    b = std::move(_tmp);
}

int main() {
    vector<string> v1  { "one", "two", "three", "four", "five" };
    vector<string> v2  { "six", "seven", "eight", "nine", "ten" };
    
    disp_t(v1);
    disp_t(v2);

    auto v3 = std::move(v2);
    printf("\nAfter the move, v2 -> v3 \n");
    disp_t(v1);
    disp_t(v2);
    disp_t(v3);

    // demo the swap
    // :: means using current scope
    // because std::swap() pretty much does the same thing
    
    ::swap(v1, v3); // use current scope
    disp_t(v1);
    disp_t(v3);

    return 0;
}
