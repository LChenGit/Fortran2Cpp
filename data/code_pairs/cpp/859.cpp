#include <iostream>
#include <cassert> // For assert()

int main() {
    int a = 3; // Initialization
    
    // Unit test to verify the value of 'a'
    assert(a == 3 && "Test failed: a is not 3");
    std::cout << "Test passed: a is 3" << std::endl;

    return 0;
}