#include <iostream>
#include <functional>
#include <complex>

template<typename Real>
void qr(std::function<void(Real)> f) {
    f(42); // Call f with a real number
}

template<typename Complex>
void qc(std::function<void(Complex)> f) {
    f(std::complex<double>(42, 0)); // Call f with a complex number
}

void realFunction(double x) {
    std::cout << "Real function called with argument: " << x << std::endl;
}

void complexFunction(std::complex<double> z) {
    std::cout << "Complex function called with argument: " << z << std::endl;
}

int main() {
    qr<double>(realFunction);
    qc<std::complex<double>>(complexFunction);
    
    return 0;
}