#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace boost::multiprecision;

int main() {
    cpp_int integer("0x7735d31fc78b9ac342f95821da36090d8abad8bc");

    std::cout << integer << std::endl;

    // 680570232729885241757213021290842004722156230844
    // verify the same number from python
    // int(hashlib.sha1("/test/1").hexdigest(), 16)

}

