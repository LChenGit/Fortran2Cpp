// File: main.cpp
#include <iostream>
#include <cassert>

// Define a character array with size 1 to simulate the Fortran character array
char c[1];

// In Fortran, the common block is used to share variables. 
// In C++, we will use a global variable.
namespace x {
    char* common_c = c;
}

void check_value() {
    assert(x::common_c[0] == 'A' && "Test Failed: c is not 'A'");
    std::cout << "Test Passed: c = " << x::common_c[0] << std::endl;
}

int main() {
    // Set the value of 'c'
    x::common_c[0] = 'A';

    // Check the value
    check_value();

    return 0;
}