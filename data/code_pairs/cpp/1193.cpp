#include <cmath>
#include <cstdlib>
#include <iostream>

bool arrayInitializationTest() {
    const int size = 2;
    float a[size];
    
    // Initialize the array
    for (int n = 1; n <= size; ++n) {
        a[n-1] = std::pow(static_cast<float>(n), 1.0f);
    }
    
    // Verify the array
    for (int n = 1; n <= size; ++n) {
        if (a[n-1] != std::pow(static_cast<float>(n), 1.0f)) {
            return false;
        }
    }
    
    return true;
}

int main() {
    if (arrayInitializationTest()) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
        std::abort();
    }
    
    return 0;
}