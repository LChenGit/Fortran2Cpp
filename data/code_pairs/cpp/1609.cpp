// atomic_ops_test.cpp
#include <atomic>
#include <cstdint>
#include <iostream>
#include <stdexcept>

void test_atomic_ops() {
    std::atomic<int32_t> a; // Assuming atomic_int_kind is equivalent to int32_t
    std::atomic<bool> c;
    int64_t b; // Equivalent to integer(8)
    bool d; // Equivalent to logical

    a.store(7);
    b = a.load();
    if (b != 7) {
        throw std::runtime_error("Atomic integer test failed.");
    }

    c.store(false);
    d = c.load();
    if (d != false) {
        throw std::runtime_error("Atomic logical test (false) failed.");
    }

    c.store(true);
    d = c.load();
    if (d != true) {
        throw std::runtime_error("Atomic logical test (true) failed.");
    }

    std::cout << "All atomic operation tests passed." << std::endl;
}

int main() {
    try {
        test_atomic_ops();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}