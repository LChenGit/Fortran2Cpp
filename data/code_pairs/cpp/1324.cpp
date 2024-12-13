#include <iostream>
#include <cassert>
#include <cmath>

void insertsortd(double* dx, int n) {
    double xtmp;
    int j;
    for (int i = 1; i < n; i++) { // Adjusted for zero-based indexing
        xtmp = dx[i];
        for (j = i - 1; j >= 0; j--) { // Adjusted loop to start from i - 1
            if (xtmp < dx[j]) {
                dx[j + 1] = dx[j];
            } else {
                break; // Replaces the 'exit' in Fortran
            }
        }
        dx[j + 1] = xtmp; // Adjusted for zero-based indexing
    }
}

int main() {
    double dx[] = {5.5, 2.2, 9.1, 3.3, 4.4};
    double dy[] = {3.1, 1.2, 2.2};
    int n_dx = sizeof(dx) / sizeof(dx[0]);
    int n_dy = sizeof(dy) / sizeof(dy[0]);

    // Expected sorted arrays
    double expected_dx[] = {2.2, 3.3, 4.4, 5.5, 9.1};
    double expected_dy[] = {1.2, 2.2, 3.1};

    insertsortd(dx, n_dx);
    insertsortd(dy, n_dy);

    // Check the sorted arrays
    for (int i = 0; i < n_dx; i++) {
        assert(std::fabs(dx[i] - expected_dx[i]) < 1e-9);
    }

    for (int i = 0; i < n_dy; i++) {
        assert(std::fabs(dy[i] - expected_dy[i]) < 1e-9);
    }

    std::cout << "Tests passed." << std::endl;

    return 0;
}