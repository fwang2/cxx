// c++ -std=c++11 vect_struct.cc -o vect_struct
//
#include <string>
#include <vector>

using namespace std;
struct point {
    int x;
    int y;
    string name;
};

vector<point> pointvec;

int main() {
    point p1 {2, 3, "point 1"};
    point p2 {4, 4, "point 2"};
    pointvec.reserve(2);
    pointvec.push_back(p1);
    pointvec.push_back(p2);

}
