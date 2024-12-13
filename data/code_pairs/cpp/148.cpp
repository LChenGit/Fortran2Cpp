// TestImplementation.h
class TestImplementation {
public:
    TestImplementation(int initialValue = 0) : i(initialValue) {}

    int getI() const { return i; }
    void setI(int value) { i = value; }

private:
    int i;
};

// main.cpp
#include <iostream>
#include <cassert>
#include "TestImplementation.h"

int main() {
    TestImplementation testObj(0);  // Initialize the object with a value of 0
    
    testObj.setI(10);
    assert(testObj.getI() == 10);  // Verify the value of 'i' after setting it to 10

    std::cout << "All tests passed." << std::endl;

    return 0;
}