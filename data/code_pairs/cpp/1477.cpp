#include <iostream>

void test_a(int value) {
    if (value == 1) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

int main() {
    int a = 1;
    test_a(a); // Simulated test
    return 0;
}