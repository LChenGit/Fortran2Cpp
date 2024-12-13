#include <complex>
#include <iostream>

void baseChange(double value) {
    std::cout << "baseChange with double: " << value << std::endl;
}

void baseChange(std::complex<float> value) {
    std::cout << "baseChange with complex<float>: " << value << std::endl;
}

void baseChange(std::complex<double> value) {
    std::cout << "baseChange with complex<double>: " << value << std::endl;
}

int main() {
    baseChange(2.0);
    baseChange(std::complex<float>(2.0f, 3.0f));
    baseChange(std::complex<double>(4.0, 5.0));

    return 0;
}