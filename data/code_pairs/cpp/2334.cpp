#include <iostream>
#include <cstdbool>

extern "C" bool L() {
    return false;
}

bool L2() {
    return false;
}

void S() {
    while (L()) {
        // Do something if L() is true
    }

    while (L2()) {
        // Do something if L2() is true
    }
}

int main() {
    // Test function L
    bool result = L();
    if(result != false) {
        std::cerr << "Test for L failed!" << std::endl;
    } else {
        std::cout << "Test for L passed." << std::endl;
    }

    // Test function L2
    result = L2();
    if(result != false) {
        std::cerr << "Test for L2 failed!" << std::endl;
    } else {
        std::cout << "Test for L2 passed." << std::endl;
    }

    // Test subroutine S (which relies on L and L2)
    S();
    std::cout << "Test for S passed (no infinite loop)." << std::endl;

    return 0;
}