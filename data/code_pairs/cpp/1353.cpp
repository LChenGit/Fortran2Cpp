#include <iostream>

namespace H5GLOBAL {
    const int H5P_DEFAULT_F = 0; // Example initialization
}

void test_H5P_DEFAULT_F() {
    if (H5GLOBAL::H5P_DEFAULT_F == 0) {
        std::cout << "TEST PASSED: H5P_DEFAULT_F is correctly defined." << std::endl;
    } else {
        std::cout << "TEST FAILED: H5P_DEFAULT_F is not correctly defined." << std::endl;
    }
}

int main() {
    test_H5P_DEFAULT_F();
    return 0;
}