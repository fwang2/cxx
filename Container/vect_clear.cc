#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    vector<int> alist = {1, 2, 3, 4};
    cout << "vec len = " << alist.size() << "\n";
    alist.clear();
    cout << " after clear len = " << alist.size() << "\n";
}

