#include <cassert>
#include <iostream>

int main() {
    bool b = true; // Initialize b to true
    // Test 1: b == b
    b = (b == b); 
    assert(b == true); // This should always be true
    std::cout << "Test 1 passed" << std::endl;

    // Test 2: b != b
    b = (b != b); 
    assert(b == false); // This should always be false
    std::cout << "Test 2 passed" << std::endl;

    return 0;
}