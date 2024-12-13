#include <iostream>
#include <vector>

float FPOLY(int NDEG, const std::vector<float>& COEFF, float X) {
    double DSUM = static_cast<double>(COEFF[NDEG]); // Adjust for zero-based indexing
    if (NDEG > 0) {
        for (int K = NDEG - 1; K >= 0; --K) { // Adjust for zero-based indexing
            DSUM = DSUM * static_cast<double>(X) + static_cast<double>(COEFF[K]);
        }
    }
    return static_cast<float>(DSUM);
}

int main() {
    std::vector<float> COEFF = {1, 2, 3}; // Polynomial coefficients for 1 + 2x + 3x^2
    float X = 2.0f; // The value of x

    float result = FPOLY(2, COEFF, X); // Calculate polynomial value

    std::cout << "Result: " << result << std::endl; // Display the result
    std::cout << "Expected: 17.0" << std::endl; // Display the expected result

    return 0;
}