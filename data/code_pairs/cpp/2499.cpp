#include <iostream>
#include <cassert>

class mmm {
public:
    int j; // Equivalent to the integer variable in the Fortran module
};

int main() {
    mmm moduleInstance; // Create an instance of the class
    moduleInstance.j = 5; // Initialize the variable

    // Check the value of j and print the result
    if (moduleInstance.j == 5) {
        std::cout << "Test passed: j == 5" << std::endl;
    } else {
        std::cout << "Test failed: j != 5" << std::endl;
    }

    // Alternatively, use assert for unit testing
    assert(moduleInstance.j == 5);

    return 0;
}