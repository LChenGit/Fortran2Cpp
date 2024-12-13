#include <iostream>

const int n = 800;
const int arraySize1 = 4; // 0 to 3 inclusive
const int arraySize2 = n; // 1 to n inclusive, but array indexing starts at 0 in C++

struct NormSplin {
    double x_norm[arraySize1][arraySize2];
    double y_norm[arraySize1][arraySize2];
    double dx;
};

int main() {
    // Create an instance of the NormSplin structure
    NormSplin normsplin;

    // Initialize values
    normsplin.dx = 1.23;

    for (int i = 0; i < arraySize1; ++i) {
        for (int j = 1; j <= n; ++j) { // Adjust loop to start at 1 for comparison with Fortran
            normsplin.x_norm[i][j-1] = static_cast<double>(i * j); // Adjust index for C++ zero-based indexing
            normsplin.y_norm[i][j-1] = static_cast<double>(i + j); // Adjust index for C++ zero-based indexing
        }
    }

    // Print some values to verify
    std::cout << "dx = " << normsplin.dx << std::endl;
    std::cout << "x_norm[0][1-1] = " << normsplin.x_norm[0][1-1] << std::endl; // Adjust print index for zero-based indexing
    std::cout << "y_norm[0][1-1] = " << normsplin.y_norm[0][1-1] << std::endl; // Adjust print index for zero-based indexing
    std::cout << "x_norm[3][n-1] = " << normsplin.x_norm[3][n-1] << std::endl; // Adjust print index for zero-based indexing
    std::cout << "y_norm[3][n-1] = " << normsplin.y_norm[3][n-1] << std::endl; // Adjust print index for zero-based indexing

    return 0;
}