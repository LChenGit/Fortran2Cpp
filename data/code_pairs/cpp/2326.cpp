#include <iostream>
#include <cstdlib> // For std::abort

namespace modproc {
    // Definition of sub function
    int sub() {
        return -5;
    }

    // Typedef for the function pointer
    using bar_t = int(*)();

    // Function pointer for x
    bar_t bar = sub;
}

// Definition of x function
int x() {
    return modproc::bar(); // Ensuring it uses the function pointer within the namespace
}

int main() {
    if (x() != -5) {
        std::cout << "Test failed: x() does not return -5" << std::endl;
        std::abort();
    } else {
        std::cout << "Test passed: x() returns -5" << std::endl;
    }

    return 0;
}