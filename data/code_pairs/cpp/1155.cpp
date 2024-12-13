#include <openacc.h>
#include <cstdlib> // for std::abort
#include <iostream>

// Global variable
int a;

#pragma acc declare create(a)

int main() {
    // Check if 'a' is present on the accelerator
    if (!acc_is_present(&a, sizeof(a))) {
        std::cout << "Test failed: variable 'a' is not on the accelerator." << std::endl;
        std::abort();
    } else {
        std::cout << "Test passed: variable 'a' is on the accelerator." << std::endl;
    }

    return 0;
}