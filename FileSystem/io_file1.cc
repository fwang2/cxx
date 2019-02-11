// demo: c++ I/O is *not* fail safe
// opening an non-existing file doesn't even generate a warning
//
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream infile("some_missing_file.xyz");
    int i;
    double d;
    infile >> i >> d;
    std::cout << "i is " << i << ", d is " << d << "\n";
    infile.close();
}
