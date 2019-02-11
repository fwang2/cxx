//
// you need to compile it with (g++ 4.4.7 works fine)
// c++ -std=c++0x -lpthread thread.cc -o hello
//
// Note ===
// without -lpthread, you get a segment fault
//
#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello concurrent world \n";
}

int main()
{
    std::thread t(hello);
    t.join();
}

