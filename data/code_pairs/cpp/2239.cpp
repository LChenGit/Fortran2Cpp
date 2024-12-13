#include <iostream>
#include <cmath>
#include <algorithm>

int ifun(int arg1, int arg2) {
    return arg1 + arg2;
}

double jfun(double arg1) {
    return std::sqrt(arg1);
}

void subr1(double a, double b) {
    double arrayA[3][4][3];
    double c = std::max(a, b);
    arrayA[0][0][0] = c;
    std::cout << "subr1 - Value is: " << c << std::endl;
}

void subr2() {
    double i = 1.0;
    int j = 2;
    int m = 3;
    double l = 4.5;

    std::cout << "inside subroutine subr2" << std::endl;
    std::cout << "IFUN RETURNS: " << ifun(j, m) << std::endl;
    std::cout << "JFUN RETURNS: " << jfun(i + l) << std::endl;
}

int main() {
    subr1(3.0, 4.0);
    subr2();
    return 0;
}