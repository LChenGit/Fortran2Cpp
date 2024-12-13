#include <iostream>
#include <complex>
#include <cstdlib>

int f1(int a) {
    return 15 + a;
}

double e1(int b) {
    return 42 + b;
}

std::complex<double> f2(int a) {
    if (a <= 0) {
        return std::complex<double>(45, 0);
    } else {
        return std::complex<double>(a < 46 ? 1 : 0, 0);
    }
}

bool e2(int a) {
    return a > 0 && a < 46;
}

float f3(int a) {
    return 15 + a;
}

bool e3(int b) {
    return b == 42;
}

std::complex<double> g3(int b) {
    return std::complex<double>(b + 11, 0);
}

bool f4(int a) {
    return a < 0;
}

int e4(int a) {
    if (a == 0) return 16 + a;
    return 0; // Assuming a default return value
}

double g4(int a) {
    if (a > 0) return 17 + a;
    return 0; // Assuming a default return value
}

void testFunctions() {
    assert(f1(6) == 21);
    assert(e1(7) == 49);
    assert(f2(0) == std::complex<double>(45, 0));
    assert(f2(45) == std::complex<double>(1, 0)); // e2 logic applied here
    assert(f2(46) == std::complex<double>(0, 0)); // e2 logic applied here
    assert(f3(17) == 32);
    assert(e3(42) == true);
    assert(e3(41) == false);
    assert(g3(12) == std::complex<double>(23, 0));
    assert(f4(-5) == true);
    assert(e4(0) == 16);
    assert(g4(2) == 19);

    std::cout << "All tests passed successfully." << std::endl;
}

int main() {
    testFunctions();
    return 0;
}