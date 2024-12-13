#include <iostream>

int bar(int a, int b) {
    return a + b;
}

void testBar(int a, int b, int expected) {
    int result = bar(a, b);
    if(result == expected) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed: Expected " << expected << ", but got " << result << "." << std::endl;
    }
}

int main() {
    // Test 1
    testBar(5, 3, 8);

    // Test 2
    testBar(-1, -1, -2);

    // Test 3
    testBar(0, 0, 0);

    return 0;
}