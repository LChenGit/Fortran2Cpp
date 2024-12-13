#include <iostream>
#include <omp.h>

bool test_array_initialization() {
    const int size = 10;
    int a[size];
    bool test_passed = true;

    #pragma omp simd
    for(int i = 0; i < size; ++i) {
        a[i] = i + 1; // Adjust for 0-based indexing to match 1-based indexing in Fortran
    }

    for(int i = 0; i < size; ++i) {
        if(a[i] != i + 1) {
            std::cerr << "Test failed for element: " << i << std::endl;
            test_passed = false;
        }
    }

    return test_passed;
}

int main() {
    if(test_array_initialization()) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Some tests failed." << std::endl;
    }

    return 0;
}