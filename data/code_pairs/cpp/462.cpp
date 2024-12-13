#include <iostream>
#include <cstdlib> // For std::exit()

void foo() {
    static union {
        int a;
        int b;
    } shared;

    shared.a = 5;
    if (shared.b != 5) {
        std::cerr << "Test failed: b is not equal to 5." << std::endl;
        std::exit(1);
    }

    // Additional test to ensure shared storage.
    shared.b = 10;
    if (shared.a != 10) {
        std::cerr << "Test failed: a is not equal to 10 after setting b to 10." << std::endl;
        std::exit(1);
    }
}

int main() {
    foo();
    std::cout << "Test passed." << std::endl;
    return 0;
}