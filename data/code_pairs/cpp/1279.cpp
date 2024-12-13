#include <complex>
#include <iostream>
#include <cassert>

struct t {
    char c;
    t(char ch) : c(ch) {}
};

void s1() {
    t x('1');
    std::cout << "s1 - x.c: " << x.c << std::endl;
}

void s2() {
    float x1 = 1.0f;
    float x2 = -1.0f;
    int i1 = 1;
    int i2 = -1;
    std::cout << "s2 - x1: " << x1 << " x2: " << x2 << " i1: " << i1 << " i2: " << i2 << std::endl;
}

void s3() {
    std::complex<float> z1(1.0f, 2.0f);
    std::complex<float> z2(-1.0f, -2.0f);
    std::cout << "s3 - z1: (" << z1.real() << ", " << z1.imag() << ") z2: (" << z2.real() << ", " << z2.imag() << ")" << std::endl;
}

int main() {
    s1();
    s2();
    s3();
    
    return 0;
}