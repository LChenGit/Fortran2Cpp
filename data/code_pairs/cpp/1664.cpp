// func0.cpp
#include <cassert>
#include <iostream>

extern "C" {
    // Declare the function to ensure it has C linkage
    void* func0();
}

int main() {
    // Call func0 and verify its behavior
    void* result = func0();
    assert(result == nullptr); // This will abort the program if the assertion fails

    std::cout << "Test passed: func0() returned a null pointer." << std::endl;

    return 0;
}

// Definition of func0 with C linkage
extern "C" void* func0() {
    return nullptr;
}