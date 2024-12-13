#include <iostream>
#include <iomanip>

double fun(double a, double b) {
    std::cout << std::setprecision(17); // To match Fortran's default output precision
    std::cout << "in sub: a,b=" << a << "," << b << std::endl;
    double result = a * b;
    std::cout << "in sub: fun=" << result << std::endl;
    return result;
}

int main() {
    double a = 1.0e-46, b = 1.0, c;
    c = fun(a, b);
    std::cout << "in main: fun=" << c << std::endl;
    return 0;
}