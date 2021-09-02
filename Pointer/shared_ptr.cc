/*

shared pointer:
* you can copy it, increase ref count by 1
* you can reset(), decrease ref count by 1
* you can check the ref count by use_count() method

*/

// demo: shared_ptr and its reference count

#include <iostream>
#include <memory>
using namespace std;

shared_ptr<double> f()
{
    shared_ptr<double> p1{new double};
    shared_ptr<double> p2{new double}, p3 = p2;

    // at this point, 1 ref to first allocation, 2 refs to second allocation
    cout << "p3.use_count() = " << p3.use_count() << endl;
    return p3;

    // once return, p1 p2 p3 all disappear, the first allocation will be
    // freed, but second allocation will persist since the main program has a
    // reference to it.
}
int main()
{

    shared_ptr<double> p = f();
    cout << "p.use_count() = " << p.use_count() << endl;
}
