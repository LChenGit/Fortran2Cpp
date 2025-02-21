#include <iostream>
#include <cassert>

void mvbits(int source, int src_pos, int nbits, int& dest, int dest_pos) {
    // Extract the nbits from source starting at src_pos
    int mask = ((1 << nbits) - 1) << src_pos;
    int extracted_bits = (source & mask) >> src_pos;

    // Clear the destination bits at dest_pos for nbits
    int clear_mask = ~(((1 << nbits) - 1) << dest_pos);
    dest &= clear_mask;

    // Insert the extracted bits into dest at dest_pos
    dest |= extracted_bits << dest_pos;
}

int main() {
    int a[2] = {1, 1};
    int b[2] = {0, 0};
    int x = 1;
    int y = 0;

    // Call mvbits for each element in the arrays
    for (int i = 0; i < 2; ++i) {
        mvbits(a[i], 0, 1, b[i], 1);
    }
    mvbits(x, 0, 1, y, 1);

    // Unit test: Check if all elements of b are equal to y
    for (int i = 0; i < 2; ++i) {
        assert(b[i] == y && "Test failed: b and y are not equal.");
    }

    std::cout << "Test passed successfully." << std::endl;
    return 0;
}