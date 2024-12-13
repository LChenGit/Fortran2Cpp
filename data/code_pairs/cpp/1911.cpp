#include <array>
#include <cassert>
#include <iostream>

std::array<std::array<float, 10>, 10> a;

int main() {
    // Initialize array for testing
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            a[i][j] = 0.0f;  // Default to 0.0
        }
    }

    // Set a known value for testing
    a[2][1] = 5.0f;  // This mimics a(3,2)[1]=5.0 in Fortran
    
    // Perform the operation similar to the original code
    a[4][5] = a[2][1];  // This mimics a(5,6)=a(3,2)[1] in Fortran

    // Test if the value at a[4][5] (a(5,6) in Fortran) is as expected
    assert(a[4][5] == 5.0f);

    std::cout << "Test passed: a[4][5] == 5.0f" << std::endl;

    return 0;
}