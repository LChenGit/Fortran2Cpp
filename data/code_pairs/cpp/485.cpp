#include <iostream>

// Define the struct as an equivalent of the Fortran COMMON block
struct EH0001 {
    int mesflg; // Assuming mesflg is used elsewhere in your code
    int lunit = 0; // Initializing to mimic Fortran default behavior
} eh0001; // Global instance

// Translate the Fortran subroutine to a C++ function
void xsetun(int lun) {
    if (lun > 0) eh0001.lunit = lun;
}

int main() {
    // Test 1: Test with a negative value
    xsetun(-1);
    if (eh0001.lunit == 0) {
        std::cout << "Test 1 passed." << std::endl;
    } else {
        std::cout << "Test 1 failed." << std::endl;
    }

    // Resetting lunit for the next test
    eh0001.lunit = 0;

    // Test 2: Test with a positive value
    xsetun(5);
    if (eh0001.lunit == 5) {
        std::cout << "Test 2 passed." << std::endl;
    } else {
        std::cout << "Test 2 failed." << std::endl;
    }

    return 0;
}