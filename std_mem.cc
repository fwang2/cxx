//
// demo std auto memory management
//
//
// http://www.modernescpp.com/index.php/automatic-memory-management-with-containers
//
#include <iostream>
#include <string>
#include <vector>

template <typename T>
void showInfo(const T& t, const std::string& name)
{
    std::cout << name << " t.size(): " << t.size() << std::endl;
    std::cout << name << " t.capacity(): " << t.capacity() << std::endl;

}

int main()
{
    using namespace std;

    cout << endl;

    string str;
    vector<int> vec;

    cout << "Maximal size: " << endl;
    cout << "   str.max_size(): " << str.max_size() << endl;
    cout << "   vec.max_size(): " << vec.max_size() << endl;
    cout << endl;

}
