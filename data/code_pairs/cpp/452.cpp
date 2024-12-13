#include <complex>

class ComplexCreator {
public:
    std::complex<double> operator()(int a, int b) const {
        return std::complex<double>(b, a);
    }
};