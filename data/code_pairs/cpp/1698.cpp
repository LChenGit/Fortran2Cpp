#include <complex>
#include <iostream>
#include <cmath> // For std::abs (for double)

double specific__abs_c8(const std::complex<double>& parm) {
    return std::abs(parm);
}

// Simple function to compare doubles with a tolerance
bool almost_equal(double x, double y, double epsilon = 1e-6) {
    return std::abs(x - y) < epsilon;
}

int main() {
    std::complex<double> test_val;
    double expected, result;

    // Test 1: Positive real and imaginary parts
    test_val = {3.0, 4.0};
    expected = 5.0;
    result = specific__abs_c8(test_val);
    std::cout << "Test 1 (3+4i): Expected 5, got " << result << " - " << (almost_equal(result, expected) ? "PASS" : "FAIL") << std::endl;

    // Test 2: Negative real part
    test_val = {-3.0, 4.0};
    result = specific__abs_c8(test_val);
    std::cout << "Test 2 (-3+4i): Expected 5, got " << result << " - " << (almost_equal(result, expected) ? "PASS" : "FAIL") << std::endl;

    // Test 3: Negative imaginary part
    test_val = {3.0, -4.0};
    result = specific__abs_c8(test_val);
    std::cout << "Test 3 (3-4i): Expected 5, got " << result << " - " << (almost_equal(result, expected) ? "PASS" : "FAIL") << std::endl;

    // Test 4: Negative real and imaginary parts
    test_val = {-3.0, -4.0};
    result = specific__abs_c8(test_val);
    std::cout << "Test 4 (-3-4i): Expected 5, got " << result << " - " << (almost_equal(result, expected) ? "PASS" : "FAIL") << std::endl;

    return 0;
}