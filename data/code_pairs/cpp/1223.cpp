#include <iostream>
#include <cmath> // for std::abs

void cddiv(const double A[2], const double B[2], double C[2]) {
    double G, H, T;

    if (std::abs(B[0]) > std::abs(B[1])) {
        H = B[0] / B[1];
        G = B[0] + H * B[1];
        T = A[0];
        C[0] = (T + H * A[1]) / G;
        C[1] = (A[1] - H * T) / G;
    } else {
        H = B[1] / B[0];
        G = B[1] + H * B[0];
        T = A[0];
        C[0] = (H * T + A[1]) / G;
        C[1] = (H * A[1] - T) / G;
    }
}

int main() {
    double A[2], B[2], C[2];

    // Test 1: Dividing two positive complex numbers
    A[0] = 2.0; A[1] = 3.0;
    B[0] = 4.0; B[1] = 5.0;
    cddiv(A, B, C);
    std::cout << "Test 1: " << C[0] << " + " << C[1] << "i" << std::endl;

    // Test 2: Dividing two negative complex numbers
    A[0] = -2.0; A[1] = -3.0;
    B[0] = -4.0; B[1] = -5.0;
    cddiv(A, B, C);
    std::cout << "Test 2: " << C[0] << " + " << C[1] << "i" << std::endl;

    // Test 3: Dividing a positive by a negative complex number
    A[0] = 2.0; A[1] = 3.0;
    B[0] = -4.0; B[1] = -5.0;
    cddiv(A, B, C);
    std::cout << "Test 3: " << C[0] << " + " << C[1] << "i" << std::endl;

    // Test 4: Real part of divisor is 0
    A[0] = 1.0; A[1] = 2.0;
    B[0] = 0.0; B[1] = 1.0;
    cddiv(A, B, C);
    std::cout << "Test 4: " << C[0] << " + " << C[1] << "i" << std::endl;

    // Test 5: Imaginary part of divisor is 0
    A[0] = 1.0; A[1] = 2.0;
    B[0] = 1.0; B[1] = 0.0;
    cddiv(A, B, C);
    std::cout << "Test 5: " << C[0] << " + " << C[1] << "i" << std::endl;

    return 0;
}