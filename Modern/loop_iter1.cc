

#include <iostream>
#include <vector>


int main() {

    using namespace std;
    std::vector<int> dvec = { 1, 2, 3, 4, 5};

    cout << "Now we use iterator" << endl;
    for (auto it = begin(dvec); it != end(dvec); it++) {
        cout << *it << "\n";
    }


    // cbegin() cend() will return "const_iterator"
    // this is a C++14 feature, won't compile under gcc 4.8.x


    // for (auto it = cbegin(dvec); it != cend(dvec); it++) {
    //     cout << *it << "\n";
    // }
}
