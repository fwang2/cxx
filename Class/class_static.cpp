/*
 * class_static.cpp
 *
 */

#include <iostream>
using namespace std;

class Bakery {
public:
	static const int Months = 12;

private:
	double costs[Months];
};

int main(void) {
	cout << Bakery::Months << endl;
}



