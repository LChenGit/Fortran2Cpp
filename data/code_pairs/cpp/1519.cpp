#include <iostream>
#include <cmath> // for std::abs

int main() {
    float a[2] = {-3.5f, 4.5f}; // Initializing with test data for completeness
    float b[2];
    
    for (int i = 0; i < 2; i++) {
        b[i] = std::abs(a[i]);
    }

    // Printing the contents of array b for demonstration
    for (int i = 0; i < 2; i++) {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    return 0;
}