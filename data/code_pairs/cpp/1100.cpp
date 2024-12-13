#include <iostream>

// Function declaration
int modResult(int a, int b) {
    return a % b;
}

// Test function
void testModFunction() {
    int result = modResult(13, 5);
    if (result == 3) {
        std::cout << "Test passed: 13 % 5 == 3" << std::endl;
    } else {
        std::cout << "Test failed: 13 % 5 != 3" << std::endl;
    }
}

int main() {
    testModFunction();
    return 0;
}