#include <iostream>
#include <complex>

extern "C" void ZTRSMF(const char& SIDE, const char& UPLO, const char& TRANSA, const char& DIAG, 
                       const int& M, const int& N, const std::complex<double>& ALPHA, 
                       std::complex<double>* A, const int& LDA, 
                       std::complex<double>* B, const int& LDB) {
    std::cout << "ZTRSMF called successfully." << std::endl;
}