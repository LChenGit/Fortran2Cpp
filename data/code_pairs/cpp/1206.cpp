#include <iostream>

// Declaration of the test function to be consistent with the Fortran subroutine
void test(int& a, int& b, int& d) {
    d = a + b; // Simple operation: sum a and b
}

// Simple testing function that does not rely on external libraries
void runTest() {
    int a = 2, b = 3, d = 0;
    test(a, b, d); // Call the function
    if (d == 5) { // Check if the function worked as expected
        std::cout << "Test Passed: d is " << d << std::endl;
    } else {
        std::cout << "Test Failed: d is " << d << ", expected 5" << std::endl;
    }
}

// Main function to run the test
int main() {
    runTest();
    return 0;
}