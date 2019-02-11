// clang compile with "c++ -std=c++11 -stdlib=libc++
#include <iostream>
#include <vector>
int main() {
    using namespace std;
    int x = {-1}; // must have =
    vector<int> alist={1, 2, 3, 4};
    for (int i=0; i<alist.size(); i++) {
        cout << alist[i] << " ";
    }
    cout << endl;

    // note how I did wrong of using alist[i] instead of just i
    // as i is really the value alist[0], alist[1] ....
    for (auto i: alist)
        cout << alist[i] << " ";
    cout << endl;
    return 0;
}
