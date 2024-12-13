// utility.hpp
namespace utility {
    int gatto = 0;

    // Function when magg is provided
    void subtract(const int& mino, int& ris, const int& magg) {
        ris = magg - mino;
        gatto = 42;
    }

    // Overloaded function when magg is not provided
    void subtract(const int& mino, int& ris) {
        ris = -mino;  // Matching Fortran behavior
        gatto = 42;
    }
}

// test_utility.cpp
#include <iostream>
#include "utility.hpp" // Assuming the translated utility code is in this header file

void testSubtractWithMagg() {
    int result;
    utility::subtract(3, result, 10); // Using magg
    if (result == 7) {
        std::cout << "Test 1 Passed" << std::endl;
    } else {
        std::cout << "Test 1 Failed" << std::endl;
    }
}

void testSubtractWithoutMagg() {
    int result;
    utility::subtract(3, result); // Not using magg
    if (result == -3) {  // Matching Fortran behavior
        std::cout << "Test 2 Passed" << std::endl;
    } else {
        std::cout << "Test 2 Failed" << std::endl;
    }
}

void testGlobalGatto() {
    if (utility::gatto == 42) {
        std::cout << "Global gatto Test Passed" << std::endl;
    } else {
        std::cout << "Global gatto Test Failed" << std::endl;
    }
}

int main() {
    testSubtractWithMagg();
    testSubtractWithoutMagg();
    testGlobalGatto();

    return 0;
}