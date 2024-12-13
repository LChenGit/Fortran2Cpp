#include <iostream>

// Variable to be tested
int x = 5;

int main() {
    // Normally, the testing code would be separate, but for simplicity's sake:
    if (x == 5) {
        std::cout << "Test passed: x equals 5." << std::endl;
    } else {
        std::cout << "Test failed: x does not equal 5." << std::endl;
    }

    return 0;
}