#include <bits/stdc++.h>

using namespace std;

string getName() {
    return "fwang2";
}

int main() {
    string name1 = getName();


    // this is a "rvalue" reference
    
    const string& name2 = getName(); // must be "const"
    cout << name2 << "\n";


    // without const, and 
    // && make it a "lvalue"
    // thus can be re-assigned.

    string&& name4 = getName(); 
    name4 = "new fwang2";
    cout << name4 << "\n";

}