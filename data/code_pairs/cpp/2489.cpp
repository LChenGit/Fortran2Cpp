#include <iostream>

union Equiv {
    int a[3];
    int b;
};

int main() {
    volatile Equiv equiv;
    
    // Initialize array
    equiv.a[0] = 10;
    equiv.a[1] = 20;
    equiv.a[2] = 30;
    
    // Print values to verify equivalence
    std::cout << "equiv.a[0]: " << equiv.a[0] << std::endl;
    std::cout << "equiv.a[1]: " << equiv.a[1] << std::endl;
    std::cout << "equiv.a[2]: " << equiv.a[2] << std::endl;
    std::cout << "equiv.b: " << equiv.b << std::endl;
    
    // Check if b is equal to a[0]
    if (equiv.b == equiv.a[0]) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }
    
    return 0;
}