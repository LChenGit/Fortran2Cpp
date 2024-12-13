#include <iostream>
#include <cstdint>

struct descr {
    void* address;
};

int main() {
    double buf[1] = {0};
    descr DD;
    DD.address = static_cast<void*>(buf);
    
    std::intptr_t i = reinterpret_cast<std::intptr_t>(DD.address);
    std::intptr_t j = reinterpret_cast<std::intptr_t>(buf);
    
    // Test 1: Check if pointers are non-null
    if (i == 0 || j == 0) {
        std::cerr << "Null pointer encountered." << std::endl;
        return 1;
    } else {
        std::cout << "Test 1 Passed." << std::endl;
    }

    // Test 2: Check if pointers are equal
    if (i != j) {
        std::cerr << "Pointers do not match." << std::endl;
        return 2;
    } else {
        std::cout << "Test 2 Passed." << std::endl;
    }

    std::cout << "All tests passed." << std::endl;
    return 0;
}