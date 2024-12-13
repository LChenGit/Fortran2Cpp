#include <iostream>
#include <cassert>
#include <cstring> // For memcmp

void blicpy(int* ia, int* ib, int n) {
    for(int i = 0; i < n; ++i) {
        ib[i] = ia[i];
    }
}

int main() {
    // Multiple-element array
    int ia[5] = {1, 2, 3, 4, 5};
    int ib[5];
    blicpy(ia, ib, 5);
    assert(memcmp(ia, ib, 5 * sizeof(int)) == 0);
    std::cout << "Multiple-element array copy passed.\n";

    // Single-element array
    int ic[1] = {10};
    int id[1];
    blicpy(ic, id, 1);
    assert(memcmp(ic, id, sizeof(int)) == 0);
    std::cout << "Single-element array copy passed.\n";

    // Empty array
    int ie[1] = {0}; // Using a dummy array for demonstration
    int if_[1] = {0}; // Initialize to a known value
    blicpy(ie, if_, 0); // This should do nothing
    // Since nothing is copied, no need for an assert here. Just a message.
    std::cout << "Empty array copy 'passed'. Note: This is a trivial case since nothing is copied.\n";

    return 0;
}