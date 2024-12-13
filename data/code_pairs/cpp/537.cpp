#include <iostream>
#include <cassert>

// Base class corresponding to Fortran 'type foo'
class foo {
public:
    // Virtual function to allow overriding in derived class
    virtual void bar(int j) {
        // Base class implementation
        std::cout << "Base bar, j: " << j << std::endl;
    }
    
    // Virtual destructor for proper cleanup of derived classes
    virtual ~foo() {}
};

// Derived class corresponding to Fortran 'type, extends(foo) :: extfoo'
class extfoo : public foo {
public:
    // Override the bar function
    void bar(int j) override {
        // Derived class implementation
        std::cout << "Derived bar, j: " << j << std::endl;
    }
};

// Simple test function to verify functionality
void test() {
    int j_base = 10;
    int j_derived = 20;
    
    foo* basePtr = new foo();
    basePtr->bar(j_base);
    
    foo* derivedPtr = new extfoo();
    derivedPtr->bar(j_derived);
    
    delete basePtr;
    delete derivedPtr;
    
    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test();
    
    return 0;
}