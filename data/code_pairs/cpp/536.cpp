#include <iostream>

int main() {
    int A = -1; // Example value; change this to test different paths
    int x = 0;

    // Equivalent conditional logic to the Fortran arithmetic IF
    if (A < 0) {
        x = x + 1;
    } else if (A == 0) {
        x = x + 2;
    } else {
        x = x + 3;
    }

    std::cout << "Test Case with A = " << A << " results in x = " << x << std::endl;

    return 0;
}