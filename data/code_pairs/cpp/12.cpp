#include <iostream>
#include <cassert>

int G01PBL(int NCHARS, int NBYTES) {
    int LEN = 1 + NCHARS + NBYTES;

    if (NCHARS > 254) {
        LEN += 2;
    }

    return LEN;
}

int main() {
    // Test case 1
    assert(G01PBL(10, 20) == 31);
    std::cout << "Test 1 passed." << std::endl;

    // Test case 2
    assert(G01PBL(254, 1) == 256);
    std::cout << "Test 2 passed." << std::endl;

    // Test case 3
    assert(G01PBL(255, 0) == 258);
    std::cout << "Test 3 passed." << std::endl;

    // Test case 4
    assert(G01PBL(300, 10) == 313);
    std::cout << "Test 4 passed." << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}