#include <iostream>

// Define namespace to mimic the Fortran common block
namespace bar {
    int a;
    int b;
}

// Function that mimics the Fortran subroutine behavior
void foo() {
    bar::a = 1;
    bar::b = 2;
}

// Unit test function
bool test_foo() {
    foo();
    return (bar::a == 1 && bar::b == 2);
}

int main() {
    if (test_foo()) {
        std::cout << "Test passed: a = " << bar::a << ", b = " << bar::b << std::endl;
    } else {
        std::cout << "Test failed: a = " << bar::a << ", b = " << bar::b << std::endl;
    }
    return 0;
}