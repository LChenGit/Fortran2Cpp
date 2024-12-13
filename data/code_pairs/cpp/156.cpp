#include <iostream>
#include <complex>

int main() {
    std::complex<double> zero(0.0, 0.0);
    std::complex<double> one_two(1.0, 2.0);
    double three = 3.0;
    double four = three + 1.0;
    std::complex<double> three_four(three, four);

    std::cout << zero << std::endl;
    std::cout << one_two << std::endl;
    std::cout << three_four << std::endl;

    return 0;
}