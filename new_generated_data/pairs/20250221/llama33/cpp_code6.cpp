#include <iostream>
#include <cassert>

// Function BKKCRYPT equivalent in C++
int bkkCrypt(int x) {
    return x;
}

int main() {
    int test1In = 255;
    int test1Out = bkkCrypt(test1In);

    if (test1In == test1Out) {
        std::cout << "TEST PASSED" << std::endl;
    }

    // Unit tests
    assert(bkkCrypt(0) == 0);
    assert(bkkCrypt(10) == 10);
    assert(bkkCrypt(-5) == -5);
    assert(bkkCrypt(255) == 255);  // Test with maximum unsigned byte value
    assert(bkkCrypt(-256) == -256);  // Test with minimum signed byte value

    std::cout << "All unit tests passed." << std::endl;

    return 0;
}