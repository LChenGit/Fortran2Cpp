#include <vector>
#include <iostream>
#include <cmath>

void dgemv(char trans, int m, int n, double alpha, const std::vector<std::vector<double>>& A,
           const std::vector<double>& x, int incx, double beta, std::vector<double>& y, int incy) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main() {
    int m = 2, n = 3;
    std::vector<std::vector<double>> A = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    std::vector<double> x = {1.0, 2.0, 3.0};
    std::vector<double> y(m, 0.0);
    char trans = 'N';
    double alpha = 1.0, beta = 1.0;
    int incx = 1, incy = 1;

    dgemv(trans, m, n, alpha, A, x, incx, beta, y, incy);

    // Expected results after the operation: y = [14, 32]
    std::vector<double> expected = {14.0, 32.0};
    bool correct = true;
    for (int i = 0; i < m; ++i) {
        if (std::abs(y[i] - expected[i]) > 1e-9) {
            correct = false;
            break;
        }
    }

    if (correct) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}