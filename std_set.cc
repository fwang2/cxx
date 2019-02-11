#include <iostream>
#include <set>

int main() {
    using namespace std;



    // multiset additionally count how often an item is inserted
    multiset<int> s = {1, 3, 4, 7, 9, 1, 1, 4};
    s.insert(4);
    for (int i = 0; i < 6; ++i) {
        cout << i << " appears " << s.count(i) << " times(s)\n";
    }
}