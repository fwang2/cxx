#include <boost/lexical_cast.hpp>
#include <iostream>
namespace boost {
    template <typename T >
    T lexical_cast(const char* str, size_t size);
}

int main() {
    std::string str = "1234";
    std::string str2 = "abc1234";
    try {
        int n = boost::lexical_cast<int>(str);
        assert(n == 1234);
        //
        // doesn't work!!!
        //
        // int m = boost::lexical_cast<int>(str.c_str() + 3, 4);
        // assert(m == 1234);
        std::cout << "cast okay" << "\n";
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
}