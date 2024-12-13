#include <iostream>

// Function to add two integers
int add(int x, int y) {
    return x + y;
}

// Unit test function for the 'add' function
void testAddFunction() {
    int x = 1, y = 2;
    int expected = 3;
    int result = add(x, y);
    if (result == expected) {
        std::cout << "Test passed: " << x << " + " << y << " = " << result << std::endl;
    } else {
        std::cout << "Test failed: Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    testAddFunction(); // Run the test
    return 0;
}