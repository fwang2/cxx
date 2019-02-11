// demo: for loop (note: not the for each)
// 

#include <iostream>
#include <vector>

int main() {
    using namespace std;
    std::vector<int> dvec = {1, 2, 3, 4, 5};
    for (auto& x: dvec) {
        cout << x << endl;
        x++;
    }

    cout << "previous loop change the value" << "\n";

    for (const auto& x: dvec) {
        cout << x << endl;
    }

    // this won't compile as it is trying to change the read-only reference
    // for (const auto& x: dvec) {
    //     x++;
    // }

}