#include <iostream>
#include <cmath>

void curved_elem_tri(long long nnodes, double xel[2][6], long long& info_curved, double& tmp) {
    const long long nnd_triangle = 6;
    if (nnodes != nnd_triangle) {
        std::cerr << "   ???" << std::endl;
        std::cerr << "curved_elem_tri: nnodes != nnd_triangle : " << nnodes << ", " << nnd_triangle << std::endl;
        std::cerr << "curved_elem_tri: Aborting..." << std::endl;
        exit(1); // Stop the program
    }

    double xel_triangle[2][nnd_triangle] = {0};
    long long i, j, i2;
    double tol = 1.0e-14;

    // Copy the first three nodes
    for (i = 0; i < 3; ++i) { // Note the change to 0-based indexing
        for (j = 0; j < 2; ++j) {
            xel_triangle[j][i] = xel[j][i];
        }
    }

    // Compute the midpoints of the edges
    for (i = 0; i < 3; ++i) {
        i2 = (i + 1) % 3;
        if (i2 == 0) i2 = 3;
        for (j = 0; j < 2; ++j) {
            xel_triangle[j][i + 3] = (xel[j][i] + xel[j][i2]) / 2.0;
        }
    }

    tmp = 0.0;
    for (i = 0; i < nnodes; ++i) {
        for (j = 0; j < 2; ++j) {
            tmp += std::pow((xel_triangle[j][i] - xel[j][i]), 2);
        }
    }

    if (std::abs(tmp) < tol) {
        info_curved = 0;
    } else {
        info_curved = 1;
    }
}

// Main function with unit test
int main() {
    double xel[2][6] = {{1.0, 2.0, 3.0, 1.5, 2.5, 3.5}, {1.0, 2.0, 3.0, 1.5, 2.5, 3.5}};
    long long info_curved;
    double tmp;

    curved_elem_tri(6, xel, info_curved, tmp);
    std::cout << "Test 1, Expected info_curved = 0, Actual: " << info_curved << std::endl;

    return 0;
}