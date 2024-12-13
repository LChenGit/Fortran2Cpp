// test_variable.cpp
#include <iostream>

int main() {
    int i = 10;  // This is an inline comment

    // Check if the value of i is correct
    if (i == 10) {
        std::cout << "Test passed: i is 10" << std::endl;
    } else {
        std::cout << "Test failed: i is not 10" << std::endl;
    }

    return 0;
}