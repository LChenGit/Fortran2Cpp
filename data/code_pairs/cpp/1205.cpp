#include <iostream>

// Function prototype
void ffunction(float& a, float& b);

int main() {
    float a = 0.0f, b = 0.0f;
    
    // Call the function
    ffunction(a, b);
    
    // Check the results
    if (a == 3.0f && b == 4.0f) {
        std::cout << "Test passed: a = " << a << ", b = " << b << std::endl;
    } else {
        std::cout << "Test failed: a = " << a << ", b = " << b << std::endl;
    }
    
    return 0;
}

// Function to be tested
void ffunction(float& a, float& b) {
    a = 3.0f;
    b = 4.0f;
}