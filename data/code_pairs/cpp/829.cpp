#include <iostream>

// Function declaration
void setValueTo2(int& a);

int main() {
    int testVar = 0;
    std::cout << "Before: testVar = " << testVar << std::endl;

    // Call the function to set testVar to 2
    setValueTo2(testVar);

    std::cout << "After: testVar = " << testVar << std::endl;

    // Test if the function works correctly
    if (testVar == 2) {
        std::cout << "Test passed: testVar is 2." << std::endl;
    } else {
        std::cout << "Test failed: testVar is " << testVar << ", expected 2." << std::endl;
    }

    return 0;
}

// Function definition
void setValueTo2(int& a) {
    a = 2;
}