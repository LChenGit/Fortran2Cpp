// File: mod_setprecision.hpp
#ifndef MOD_SETPRECISION_HPP
#define MOD_SETPRECISION_HPP

namespace mod_setprecision {
    constexpr int sprec = sizeof(float);
    constexpr int dprec = sizeof(double);
}

#endif // MOD_SETPRECISION_HPP

// File: test_mod_setprecision.cpp
#include "mod_setprecision.hpp"
#include <iostream>

int main() {
    bool tests_passed = true;

    if (mod_setprecision::sprec != sizeof(float)) {
        std::cout << "Test for single precision failed." << std::endl;
        tests_passed = false;
    } else {
        std::cout << "Test for single precision (sprec) passed." << std::endl;
    }

    if (mod_setprecision::dprec != sizeof(double)) {
        std::cout << "Test for double precision failed." << std::endl;
        tests_passed = false;
    } else {
        std::cout << "Test for double precision (dprec) passed." << std::endl;
    }

    if (tests_passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return !tests_passed;
}