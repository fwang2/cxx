// This is to demonstrate the use of
// "std::bind()"

// basically, what bind does is:
// take a callable something,
// create a new callable (return val is undefined)

#include <functional>
#include <iostream>


void print(const int &i) {
    std::cout << i << '\n';
}


void print2(const int & i, const std::string& s ) {
    std::cout << i << ",  " <<  s << '\n';
}

int main() {
    int i = 5;
    
    // Case 1:
    // since return is "not specified", we have to use auto to catch it
    const auto f = std::bind(&print, i);
    f();  // expect output is 5

    i = 6;
    f(); // output is still 5, the bind is done at previous time

    // Case 2:
    // this is how we bind if we want to binding parameters to go with it
    const auto f2 = std::bind(&print, std::ref(i));
    f2();
    i = 7;
    f2();  // now f2() output 7 

    // Case 3: 
    // we want to first value to be bound still by i
    // but we want the 2nd value to be provided by the caller.

    const auto f3 = std::bind(&print2, std::ref(i), std::placeholders::_1);
    f3("hello");
    f3("world");

    // Case 4:
    // bind allows use to change parameters older:
    const auto f4 = std::bind(&print2, std::placeholders::_2, std::placeholders::_1);
    f4("my", i);

    // this is how bind "swallow" the rest of the parameters
    f4("god", 1, 3, 4);
}