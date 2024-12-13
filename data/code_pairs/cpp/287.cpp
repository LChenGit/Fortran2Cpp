#include <iostream>
#include <cstdlib> // For abort()

void foo(int* v) {
    v[0] = 2;
}

bool testFoo() {
    int testArray[1] = {1}; // Initialize test array
    foo(testArray); // Modify the test array using the function
    
    // Check if the modification is as expected
    return testArray[0] == 2;
}

int main() {
    if (testFoo()) {
        std::cout << "Test Passed: The first element is correctly set to 2." << std::endl;
    } else {
        std::cout << "Test Failed: The first element is not 2." << std::endl;
        std::abort();
    }

    return 0;
}