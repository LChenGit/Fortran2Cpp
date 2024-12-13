// myModule.hpp
int myFunction(int x) {
    return x * 2;
}

// test_myFunction.cpp
#include <iostream>
#include "myModule.hpp"

int main() {
    int result = myFunction(5);
    if (result == 10) {
        std::cout << "Test passed: The result is: " << result << std::endl;
    } else {
        std::cout << "Test failed: The result is: " << result << std::endl;
    }
    return 0;
}