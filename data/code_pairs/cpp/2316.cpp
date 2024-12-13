#include <iostream>
#include <cstdlib>

class DefaultInitialization {
public:
    int x = 42; // Default value for x

    // Constructor
    DefaultInitialization() = default;
};

// Create an instance of the class
DefaultInitialization t;

void test() {
    // Check if the default value is correctly set
    if (t.x != 42) {
        std::cerr << "Test failed: Initial value of t.x is not 42" << std::endl;
        std::abort();
    } else {
        std::cout << "Test passed: Initial value of t.x is correct" << std::endl;
    }

    // Modify the value and check again
    t.x = 0;
    if (t.x != 0) {
        std::cerr << "Test failed: Modified value of t.x is not 0" << std::endl;
        std::abort();
    } else {
        std::cout << "Test passed: Modified value of t.x is correct" << std::endl;
    }
}

int main() {
    test();
    return 0;
}