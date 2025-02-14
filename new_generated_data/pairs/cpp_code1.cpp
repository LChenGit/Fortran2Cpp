#include <iostream>
#include <cstdint>

void bar(int8_t a, int8_t b) {
    if (a != b) {
        std::cerr << "Error: a != b" << std::endl;
        std::cerr << "a = " << static_cast<int>(a) << std::endl;
        std::cerr << "b = " << static_cast<int>(b) << std::endl;
        throw;  // Consider specific exception handling
    }
}

void foo(int8_t ii) {
    int8_t b = ii;
    bar(ii, b);
}

int main() {
    try {
        foo(7);
        foo(0);
        foo(127);
        foo(-128);
        std::cout << "All tests passed!" << std::endl;
    } catch (...) {
        return 1;  // Indicate error
    }
    
    return 0;
}