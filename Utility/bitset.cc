#include <bitset>
#include <iostream>

using namespace std;

namespace Flag {
enum State {
    Read = 1 << 0,
    Write = 1 << 1,
    Binary = 1 << 2,
};
}

namespace Plain {
enum State { Read, Write, Binary, Count };
}

int main() {
    unsigned int state = Flag::Read | Flag::Binary;
    std::cout << state << std::endl;

    state |= Flag::Write;
    state &= ~(Flag::Read | Flag::Binary);
    std::cout << state << std::endl;



    // use bitset now
    //
    std::bitset<Plain::Count> xstate;
    xstate.set(Plain::Read);
    xstate.set(Plain::Binary);
    std::cout << xstate.to_ulong() << std::endl;

    xstate.flip();
    std::cout << xstate.to_ulong() << std::endl;

    return 0;
}
