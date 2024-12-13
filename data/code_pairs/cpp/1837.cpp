// main.cpp
#include <iostream>
#include <memory>

struct t {
    std::unique_ptr<int> caf;
};

int main() {
    t x, y;
    int* ptr = nullptr;

    y.caf = std::make_unique<int>(6);  // Directly assign 6 to y.caf
    ptr = y.caf.get();

    if (y.caf == nullptr) {
        std::cerr << "Allocation failed" << std::endl;
        return 1;
    }
    if (*y.caf != 6) {
        std::cerr << "Value assignment failed" << std::endl;
        return 1;
    }

    *ptr = 123;
    if (*y.caf != 123) {
        std::cerr << "Value reassignment failed" << std::endl;
        return 1;
    }

    // Simulating the Fortran behavior by manually copying the value, not sharing ownership
    x.caf = std::make_unique<int>(*y.caf);

    *ptr = 456; // This change will not affect x.caf if they do not share the same memory
    if (*y.caf != 456) {
        std::cerr << "y.caf was not updated" << std::endl;
        return 1;
    }
    if (*x.caf == 456) { // x.caf should remain unchanged if it doesn't share memory with y.caf
        std::cerr << "Memory sharing failed" << std::endl;
        return 1;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}