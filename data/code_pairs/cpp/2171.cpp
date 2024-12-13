#include <iostream>
#include <cassert>

namespace m1 {
    extern int i; // Declaration of the external variable
}

int m1::i; // Definition of the external variable

void test_variable_i() {
    m1::i = 10; // Assign a value to i

    // Check if the value is correctly assigned
    if (m1::i != 10) {
        std::cerr << "Test failed: i is not equal to 10" << std::endl;
        std::exit(EXIT_FAILURE);
    } else {
        std::cout << "Test passed: i is equal to 10" << std::endl;
    }
}

int main() {
    // Run the test
    test_variable_i();
    return 0;
}