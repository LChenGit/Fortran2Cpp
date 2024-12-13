#include <iostream>
#include <complex>

// Assuming these functions are part of your program logic
std::complex<double> computeConjugate(const std::complex<double>& K) {
    return std::conj(K);
}

double computeImaginaryPart(const std::complex<double>& K) {
    return imag(K);
}

// Main program for demonstration, might not be necessary if you only run tests.
int main() {
    std::complex<double> K(3.0, 4.0);
    std::cout << computeConjugate(K) << std::endl;
    std::cout << computeImaginaryPart(K) << std::endl;
    return 0;
}

// Test file (e.g., test.cpp)
#include <gtest/gtest.h>

TEST(ComplexNumberTest, ConjugateTest) {
    std::complex<double> K(3.0, 4.0);
    std::complex<double> expectedConjugate(3.0, -4.0);

    ASSERT_EQ(computeConjugate(K), expectedConjugate);
}

TEST(ComplexNumberTest, ImaginaryPartTest) {
    std::complex<double> K(3.0, 4.0);
    double expectedImaginaryPart = 4.0;

    ASSERT_EQ(computeImaginaryPart(K), expectedImaginaryPart);
}

// If the test code is in a separate file, you need another main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}