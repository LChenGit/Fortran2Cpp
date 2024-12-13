#include <iostream>
#include <cmath> // For fabs()

double factori(int n);

int main() {
    bool allTestsPassed = true;

    // Test cases
    struct TestCase {
        int input;
        double expected;
    };

    TestCase tests[] = {
        {0, 1.0},
        {1, 1.0},
        {2, 2.0},
        {3, 6.0},
        {4, 24.0},
        {5, 120.0},
        {6, 720.0},
        {7, 5040.0},
        {8, 40320.0},
        {9, 362880.0},
        {10, 3628800.0},
    };

    for (const auto& test : tests) {
        double result = factori(test.input);
        if (fabs(result - test.expected) > 0.001) {
            std::cerr << "Test failed: factori(" << test.input << ") = "
                      << result << ", expected " << test.expected << std::endl;
            allTestsPassed = false;
        }
    }

    if (allTestsPassed) {
        std::cout << "All tests passed successfully." << std::endl;
    }

    return 0;
}

double factori(int n) {
    if (n == 0 || n == 1) {
        return 1.0;
    } else {
        double result = 1.0;
        for (int i = 2; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
}