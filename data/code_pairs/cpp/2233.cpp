#include <iostream>
#include <cstdlib> // For std::abort

struct xyz {
    int x;
    xyz() : x(123) {} // Constructor to initialize x to 123
};

int main() {
    xyz a; // Create an instance of xyz with default initialization
    xyz b; // Create another instance of xyz with default initialization

    // Test 1: Check if a.x is initialized to 123
    if (a.x != 123) {
        std::cout << "Test 1 Failed: a.x is not 123" << std::endl;
        std::abort();
    } else {
        std::cout << "Test 1 Passed" << std::endl;
    }

    // Test 2: Check if b.x is initialized to 123
    if (b.x != 123) {
        std::cout << "Test 2 Failed: b.x is not 123" << std::endl;
        std::abort();
    } else {
        std::cout << "Test 2 Passed" << std::endl;
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}