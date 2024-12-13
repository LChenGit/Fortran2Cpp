#include <iostream>

int main() {
    // Dynamically allocate memory for a single integer
    int* x = new int;
    
    // Explicitly assigning a value for testing
    *x = 123;

    // Test condition
    if (*x == 123) {
        std::cout << "Test passed: x is correctly assigned." << std::endl;
    } else {
        std::cout << "Test failed: incorrect assignment." << std::endl;
    }

    // Free the allocated memory
    delete x;
    
    return 0;
}