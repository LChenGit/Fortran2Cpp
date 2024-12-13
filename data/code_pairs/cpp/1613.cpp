#include <array>
#include <cassert>
#include <cmath> // For std::fabs

double r3dot(const std::array<double, 3>& x, const std::array<double, 3>& y) {
    return x[0] * y[0] + x[1] * y[1] + x[2] * y[2];
}

int main() {
    std::array<double, 3> x = {1.0, 2.0, 3.0};
    std::array<double, 3> y = {4.0, 5.0, 6.0};

    // Test 1
    double result = r3dot(x, y);
    assert(std::fabs(result - 32.0) < 1e-9); // Using a small threshold for floating-point comparison

    // The program will terminate if the assertion fails. If it passes, the program will complete successfully.
    // Optionally, you could add a message to indicate successful completion if desired.

    return 0;
}