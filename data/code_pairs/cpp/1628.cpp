#include <iostream>
#include <vector>
#include <complex>

void ZAdd(const std::vector<std::complex<double>>& A, 
          const std::vector<std::complex<double>>& B, 
          std::vector<std::complex<double>>& C, 
          int N) {
    for (int j = 0; j < N; j++) {
        C[j] = A[j] + B[j];
    }
}

int main() {
    std::vector<std::complex<double>> A = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    std::vector<std::complex<double>> B = {{6.0, 5.0}, {4.0, 3.0}, {2.0, 1.0}};
    std::vector<std::complex<double>> C(3); // Initialize with size 3

    ZAdd(A, B, C, 3);

    std::cout << "Result of A + B:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << C[i].real() << " + " << C[i].imag() << "i" << std::endl;
    }

    return 0;
}