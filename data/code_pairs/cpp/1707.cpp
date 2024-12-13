#include <iostream>
#include <omp.h>

int main() {
    const int n = 5;
    float a[n][n], b[n][n], c[n][n];
    int errors = 0;

    // Initialize arrays
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = i + j + 1; // Adjusted for 0-based indexing to match Fortran operation
            c[i][j] = i - j;
        }
    }

    // Perform the array operation
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = b[i][j] + c[i][j];
        }
    }

    // Check the results
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != 2 * (i + 1)) { // Adjusted for 0-based indexing to match Fortran check
                errors++;
            }
        }
    }

    if (errors == 0) {
        std::cout << "Array operation test PASSED." << std::endl;
    } else {
        std::cout << "Array operation test FAILED." << std::endl;
    }

    return 0;
}