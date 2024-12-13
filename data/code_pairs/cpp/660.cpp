#include <iostream>

int fact(int x) {
    if (x <= 1) {
        return 1;
    } else {
        return x * fact(x - 1);
    }
}

int main() {
    const int expected[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    bool all_tests_passed = true;

    for (int i = 0; i < 10; ++i) {
        int result = fact(i + 1); // Adjust for zero-based indexing
        if (result != expected[i]) {
            std::cerr << "Test failed for i = " << i + 1 << ". Expected: " << expected[i] << ", Got: " << result << std::endl;
            all_tests_passed = false;
        } else {
            std::cout << "Test passed for i = " << i + 1 << ". Expected: " << expected[i] << ", Got: " << result << std::endl;
        }
    }

    if (all_tests_passed) {
        std::cout << "All tests passed successfully." << std::endl;
    }

    return !all_tests_passed; // Return 0 for success, 1 for failure
}