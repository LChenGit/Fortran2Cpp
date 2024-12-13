#include <iostream>
#include <cassert> // For assert()

int A; // Global variable, equivalent to Fortran's COMMON block /T/

void A22_4_WRONG() {
    // In the original Fortran code, this subroutine doesn't do anything.
    // This is where you would work with 'A' if needed.
}

void testA22_4_WRONG() {
    A = 5; // Modify A, as part of the test setup.
    A22_4_WRONG(); // Call the function that is supposed to work with 'A'.
    assert(A == 5); // Verify that 'A' is still 5 after calling A22_4_WRONG.
    std::cout << "Test Passed: A is 5" << std::endl;
}

int main() {
    testA22_4_WRONG(); // Run the test.
    return 0;
}