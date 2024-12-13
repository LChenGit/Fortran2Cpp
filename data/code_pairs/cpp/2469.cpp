#include <iostream>
#include <cassert>
#include <Eigen/Dense>

using namespace Eigen;

// Function to transpose a matrix
void sub(const MatrixXf& a, MatrixXf& b) {
    b = a.transpose();
}

// Test functions (assuming a simple test framework)
void testTranspose() {
    MatrixXf a(2, 2);
    a << -2, 3,
         -5, 7;
    MatrixXf expected_b(2, 2);
    expected_b << -2, -5,
                   3,  7;
    MatrixXf b;
    sub(a, b);
    assert(b.isApprox(expected_b));
    std::cout << "Transpose test passed." << std::endl;
}

void testMultiply() {
    MatrixXf a(2, 2);
    a << -2, 3,
         -5, 7;
    MatrixXf b(2, 2);
    b << -2, -5,
          3,  7;
    MatrixXf expected_b2(2, 2);
    expected_b2 << -11, 15,
                   -25, 34;
    MatrixXf result = b.transpose() * a;
    assert(result.isApprox(expected_b2));
    std::cout << "Multiply test passed." << std::endl;
}

int main() {
    testTranspose();
    testMultiply();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}