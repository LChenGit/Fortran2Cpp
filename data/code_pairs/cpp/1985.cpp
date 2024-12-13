#include <iostream>
#include <vector>

// Function to initialize a matrix to zero
void initializeMatrixToZero(std::vector<std::vector<double>>& c, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0.0;
        }
    }
}

// Test function to verify the matrix is correctly initialized to zero
bool testInitializeMatrixToZero() {
    int n = 3; // Example size of the matrix
    std::vector<std::vector<double>> c(n, std::vector<double>(n, -1.0)); // Initializing with non-zero values to check the function
    
    initializeMatrixToZero(c, n); // Initializing matrix 'c' to zero
    
    // Check if all elements are zero
    for (const auto& row : c) {
        for (double val : row) {
            if (val != 0.0) {
                std::cerr << "C++ Test Failed: Matrix element is not zero." << std::endl;
                return false;
            }
        }
    }
    
    std::cout << "C++ Test Passed: Matrix is correctly initialized to zero." << std::endl;
    return true;
}

int main() {
    testInitializeMatrixToZero();
    return 0;
}