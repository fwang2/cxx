// https://www.quora.com/How-do-I-generate-true-random-binary-numbers-in-C++

#include <iostream>
#include <random>
using namespace std;

int main()
{
    mt19937 e(random_device{}());
    bernoulli_distribution d;
    for (int n = 0; n < 100; ++n) cout << d(e) << endl;
}
