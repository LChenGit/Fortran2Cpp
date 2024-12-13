#include <iostream>

int main() {
    int i = 1;
    int test_result;

    if (i > 0) {
        i = 2;
    } else if (i > 10) {
        i = 3;
    } else {
        i = 4;
    }

    // Unit test to check the value of i
    if (i == 2) {
        test_result = 1;  // Test passed
    } else {
        test_result = 0;  // Test failed
    }

    std::cout << "Test result: " << test_result << std::endl;

    return 0;
}