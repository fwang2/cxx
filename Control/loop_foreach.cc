// demo: std array
//
// loop and process
//
#include <iostream>
#include <array>
#include <vector>
#include <algorithm> // needed by for_each

int main()
{
    using namespace std;

    cout << endl;
    array<int, 10> cppArr={1,2,3,4,5,6,7,8,9,10}; // ignore the warning emitted from lower version of gcc (4.7)
                                                    // from 4.8 on, this is
                                                    // no longer an issue
    cout << "Original array value: \n";
    for_each(cppArr.begin(), cppArr.end(), [](int v){cout << v << " ";});
    cout << endl;

    // calculate the sum of the array by using a global variable
    int sum = 0;
    for_each(cppArr.begin(), cppArr.end(), [&sum](int v) { sum += v; });
    cout << "sum of array: " << sum << endl;

    // change array value
    for_each(cppArr.begin(), cppArr.end(), [](int& v) {v=v*v;});
    cout << "array values has been changed to v*v, print it again\n";
    for_each(cppArr.begin(), cppArr.end(), [](int v){cout << v << " ";});
    cout << endl;

    cout << endl;
    cout << "we can use std::begin() and end() on regular C array as well \n";
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for_each(begin(arr), end(arr), [](int v){ cout << v << " "; });
    cout << endl;


}
