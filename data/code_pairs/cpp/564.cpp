#include <iostream>

namespace mTypes {
    constexpr int rb = 8;
    constexpr int sl = 128;
}

int main() {
    bool tests_passed = true;

    if(mTypes::rb != 8) {
        std::cout << "Test rb FAIL" << std::endl;
        tests_passed = false;
    } else {
        std::cout << "Test rb PASS" << std::endl;
    }

    if(mTypes::sl != 128) {
        std::cout << "Test sl FAIL" << std::endl;
        tests_passed = false;
    } else {
        std::cout << "Test sl PASS" << std::endl;
    }

    if(tests_passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return tests_passed ? 0 : 1;
}