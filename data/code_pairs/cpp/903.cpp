#include <iostream>
#include <cassert>

// Using namespace to simulate Fortran module
namespace bad {
    
    // C++ class to represent Fortran type with default initialization
    class DefaultInitialization {
    public:
        int x = 42; // Default initialization
    };

    // Instance of class to simulate the type declaration in Fortran
    DefaultInitialization t;
}

int main() {
    // Unit test for default initialization
    assert(bad::t.x == 42 && "Test failed: t.x is not initialized to 42.");
    std::cout << "Test passed: t.x is correctly initialized to 42." << std::endl;
    return 0;
}