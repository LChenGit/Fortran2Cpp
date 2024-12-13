#include <iostream>
#include <vector>

float f() {
    return 1.0f;
}

int main() {
    int a;
    int I;
    std::vector<bool> B(2);

    // Test 1: Test function f()
    if (f() == 1.0f) {
        std::cout << "Test 1 Passed\n";
    } else {
        std::cout << "Test 1 Failed\n";
    }
    
    // Setup for Test 2
    B = {true, false};
    if (std::any_of(B.begin(), B.end(), [](bool val) { return val; })) {
        a = 12;
    } else {
        a = 0;
    }
    if (a == 12) {
        std::cout << "Test 2 Passed\n";
    } else {
        std::cout << "Test 2 Failed\n";
    }
    
    // Setup for Test 3
    I = 1;
    if (I != 0) {
        a = 12;
    } else {
        a = 0;
    }
    if (a == 12) {
        std::cout << "Test 3 Passed\n";
    } else {
        std::cout << "Test 3 Failed\n";
    }
    
    return 0;
}