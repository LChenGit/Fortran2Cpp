// test_atomic_operations.cpp
#include <atomic>
#include <cstdint>
#include <iostream>

int main() {
    std::atomic<int32_t> a{7}; 
    std::atomic<int32_t> b;
    std::atomic<bool> d{true}, e{true};

    // Perform atomic operations
    b.store(a.load(std::memory_order_relaxed), std::memory_order_relaxed);

    // Output results
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b.load(std::memory_order_relaxed) << "\n";
    std::cout << "d: " << d << "\n";
    std::cout << "e: " << e << "\n";

    return 0;
}