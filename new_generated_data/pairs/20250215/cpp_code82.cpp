#include <iostream>
#include <cassert>

using namespace std;

void mvbits(int from, int from_pos, int length, int& to, int to_pos) {
    int mask = ((1 << length) - 1) << from_pos;
    int bits = (from & mask) >> from_pos;

    int clear_mask = ~(((1 << length) - 1) << to_pos);
    to &= clear_mask;

    to |= bits << to_pos;
}

int main() {
    int a = 1;
    int b = 0;
    int x = 1;
    int y = 0;

    mvbits(a, 0, 1, b, 1);
    mvbits(x, 0, 1, y, 1);

    // Unit test assertion
    assert(b == y && "Test case failed: assertion failed");

    return 0;
}