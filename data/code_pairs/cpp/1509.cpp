#include <iostream>

// Declare functions to be used
void pr43337(int* b);
void foo(int* b);
void bar(int* b);

void pr43337(int* b) {
    foo(b); // Fill array with 1s
    bar(b); // This also fills array with 1s, but is redundant in this context
}

void foo(int* b) {
    for (int a = 0; a < 10; ++a) {
        b[a] = 1;
    }
}

void bar(int* b) {
    for (int a = 0; a < 10; ++a) {
        b[a] = 1;
    }
}

// Simple test function to verify the functionality
void testPr43337() {
    int b[10]; // Local array to test with
    bool testPassed = true;

    pr43337(b); // Call the function to test

    // Check if all elements of the array are set to 1
    for (int i = 0; i < 10; ++i) {
        if (b[i] != 1) {
            testPassed = false;
            std::cout << "Test failed at index " << i << " with value " << b[i] << std::endl;
        }
    }

    if (testPassed) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }
}

int main() {
    // Run the test
    testPr43337();
    return 0;
}