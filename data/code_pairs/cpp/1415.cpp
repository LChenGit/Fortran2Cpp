#include <iostream>
#include <cstdlib> // For exit()
#include <cassert>

void checkv(int& ires, int a[][3], int rows, int cols, int opt1 = -1) {
    if (opt1 == -1) {
        ires = rows * cols;
    } else if (opt1 == 1) {
        ires = rows;
    } else if (opt1 == 2) {
        ires = cols;
    } else {
        std::cerr << "Invalid dimension specified for size calculation." << std::endl;
        std::exit(1);
    }
}

int main() {
    int a[2][3]; // Equivalent to Fortran's 'integer :: a(2,3)'
    int ires;

    // Test 1: Without optional parameter
    checkv(ires, a, 2, 3);
    assert(ires == 6);
    std::cout << "Test 1 passed." << std::endl;
    
    // Test 2: With optional parameter
    checkv(ires, a, 2, 3, 1);
    assert(ires == 2);
    std::cout << "Test 2 passed." << std::endl;

    return 0;
}