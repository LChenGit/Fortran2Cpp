#include <iostream>
#include <cassert>
#include <cmath>  // Include this header to use fabs

using namespace std;

bool has_close_elements(const double* a, const double* b, int size, double tolerance) {
    for (int i = 0; i < size; ++i) {
        if (fabs(a[i] - b[i]) > tolerance) {
            return false;
        }
    }
    return true;
}

void OPNONSYM(int n, double* p, double* W, double* U, double* AD, double* Au, int* JQ, int* IROW) {
    for (int i = 0; i < n; i++) {
        U[i] = AD[i] * W[i];
    }
    
    for (int j = 0; j < n; j++) {
        int start = JQ[j];
        int end = JQ[j + 1] - 1;
        for (int l = start; l <= end; l++) {
            int i = IROW[l];
            U[i] += Au[l] * W[j];
        }
    }
}

int main() {
    int n = 5;
    double W[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double U[] = {0.0, 0.0, 0.0, 0.0, 0.0};
    double AD[] = {2.0, 2.0, 2.0, 2.0, 2.0};
    double Au[] = {1.0, 1.0, 1.0, 1.0, 1.0};
    int JQ[] = {0, 2, 4, 5, 5, 5};
    int IROW[] = {0, 1, 2, 3, 4};

    // Compute using the C++ subroutine
    OPNONSYM(n, NULL, W, U, AD, Au, JQ, IROW);

    // Expected results based on the Fortran code's output
    double expected_U[] = {3.0, 5.0, 8.0, 10.0, 13.0};

    // Tolerance for floating-point comparison
    const double tolerance = 1e-6;

    // Perform the unit test
    if (!has_close_elements(U, expected_U, n, tolerance)) {
        cerr << "Test failed: Results do not match expected values." << endl;
        return 1;
    }

    cout << "Unit test passed successfully." << endl;

    return 0;
}