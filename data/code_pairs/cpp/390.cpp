// main.cpp
#include <iostream>
#include <cassert>

void sub(float& a, int i = -1);

int main() {
    float a;
    int i;
    
    // Test 1: Call sub without optional parameter
    a = 10.0f;
    sub(a);
    assert(a == 10.0f); // Assuming sub doesn't modify 'a'
    std::cout << "Test 1 passed: a is " << a << std::endl;
    
    // Test 2: Call sub with optional parameter
    a = 20.0f;
    i = 5;
    sub(a, i);
    assert(a == 20.0f); // Again, assuming sub doesn't modify 'a'
    assert(i == 5); // This assertion doesn't test sub's behavior but demonstrates passing 'i'
    std::cout << "Test 2 passed: a is " << a << ", i is " << i << std::endl;
    
    return 0;
}

void sub(float& a, int i) {
    if (i == -1) {
        std::cout << "I is not provided" << std::endl;
    } else {
        std::cout << "I is provided: " << i << std::endl;
    }
    // Normally, you would perform some operations here
}