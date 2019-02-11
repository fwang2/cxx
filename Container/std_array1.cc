// demo: std array
//
// (1) memory efficiency
//
#include <iostream>
#include <array>
#include <vector>

int main()
{
    using namespace std;

    cout << endl;
    cout << "sizeof(int) = " << sizeof(int) << endl;
    int cArr[10] = {1,2,3,4,5,6,7,8,9,10};
    array<int, 10> cppArr={1,2,3,4,5,6,7,8,9,10}; // ignore the warning emitted from lower version of gcc (4.7)
                                                    // from 4.8 on, this is
                                                    // no longer an issue
    vector<int> cppVec={1,2,3,4,5,6,7,8,9,10};
    cout << "sizeof(cArr) = " << sizeof(cArr) << endl;
    cout << "sizeof(cppArr) = " << sizeof(cppArr) << endl;
    size_t extra = sizeof(int) * cppVec.capacity();
    cout << "sizeof(cppVec) = " << sizeof(cppVec) + extra << endl;
    cout << "               = sizeof(cppVec) = " << sizeof(cppVec) << endl;
    cout << "               + sizeof(int)* cppVec.capacity() = " << extra << endl;
    cout << "\nNote: 24 extra bytes on heap are needed to managed the vector\n" << endl;
}

