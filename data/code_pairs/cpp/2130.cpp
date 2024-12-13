#include <iostream>
#include <vector>
#include <cassert>

// Function to compute the dot product
double fdot(const std::vector<double>& a, const std::vector<double>& b, int n) {
    double fdot = 0.0;
    for (int i = 0; i < n; ++i) {
        fdot += a[i] * b[i];
    }
    return fdot;
}

int main() {
    // Example test vectors
    std::vector<double> a = {1.0, 2.0, 3.0};
    std::vector<double> b = {4.0, 5.0, 6.0};
    int n = 3;

    // Calculate the dot product
    double result = fdot(a, b, n);

    // Print the result
    std::cout << "Dot product: " << result << std::endl;

    // Assert the result to ensure correctness
    assert(result == 32.0);
    std::cout << "Test passed!" << std::endl;

    return 0;
}