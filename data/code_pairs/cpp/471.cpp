#include <array>
#include <iostream>

int main() {
    // Initialize the array with true.
    std::array<bool, 10> A;
    A.fill(true); // Similar to setting all elements to .TRUE.

    // Unit test: Check if all elements are true.
    for (size_t i = 0; i < A.size(); ++i) {
        if (!A[i]) {
            std::cout << "Test Failed at index: " << i << std::endl;
            return 1; // Use return value to indicate failure in traditional unit testing.
        }
    }
    std::cout << "All tests passed." << std::endl;
    return 0; // Indicate success.
}