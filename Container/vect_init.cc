#include <vector>
#include <cstdio>

int main(void) {
    std::vector<int> time = std::vector<int>(1000, 0);

    time = std::vector<int>(10000, 0);
    printf("10000 elements created, initialized to 0\n");
    return 0;
}

