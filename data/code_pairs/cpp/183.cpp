#include <iostream>
#include <cmath>

int main() {
    bool allTestsPassed = true;

    // ANINT Test
    if (std::round(1.2) == 1.0) {
        std::cout << "ANINT Test Passed" << std::endl;
    } else {
        std::cout << "ANINT Test Failed" << std::endl;
        allTestsPassed = false;
    }

    // AINT Test
    if (std::trunc(1.2) == 1.0) {
        std::cout << "AINT Test Passed" << std::endl;
    } else {
        std::cout << "AINT Test Failed" << std::endl;
        allTestsPassed = false;
    }

    // ATAN(ANINT) Test
    if (std::atan(std::round(1.2)) == std::atan(1.0)) {
        std::cout << "ATAN(ANINT) Test Passed" << std::endl;
    } else {
        std::cout << "ATAN(ANINT) Test Failed" << std::endl;
        allTestsPassed = false;
    }

    // ATAN(AINT) Test
    if (std::atan(std::trunc(1.2)) == std::atan(1.0)) {
        std::cout << "ATAN(AINT) Test Passed" << std::endl;
    } else {
        std::cout << "ATAN(AINT) Test Failed" << std::endl;
        allTestsPassed = false;
    }

    // Overall result
    if (allTestsPassed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}