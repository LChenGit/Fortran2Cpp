#include <iostream>
#include <array>

void where_5();

int main() {
    try {
        where_5();
        std::cout << "C++ Test Passed" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "C++ Test Failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

void where_5() {
    std::array<int, 5> a = {1, 2, 3, 4, 5};
    std::array<double, 5> b = {1.0, 0.0, 1.0, 0.0, 1.0};

    for (size_t i = 0; i < a.size(); ++i) {
        if (b[i] != 0.0) {
            a[i] += 10;
        }
    }

    std::array<int, 5> expected_a = {11, 2, 13, 4, 15};
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != expected_a[i]) {
            throw std::runtime_error("a[" + std::to_string(i) + "] = " + std::to_string(a[i]) + " does not match expected value " + std::to_string(expected_a[i]));
        }
    }
}