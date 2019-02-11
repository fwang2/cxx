#include <stdint.h>
#include <iostream>
using namespace std;

int main(void) {

	uint32_t flag1 = 0xFFFFFFFF;
	uint32_t flag2 = ~0;

	if (flag1 == flag2) {
		cout << "Flags are the same" << endl;
	} else {
		cout << "Flags are NOT the same" << endl;
	}

	return 0;
}

