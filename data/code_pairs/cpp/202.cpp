// main.cpp
#include <iostream>
#include <cmath>

float e1(float x) {
    return x * 3.0f;
}

void e2(float& a, float b) {
    a = a + b;
}

int main() {
    float (*fp)(float) = nullptr;
    fp = e1;

    if (std::abs(fp(2.5f) - 7.5f) > 0.01f) {
        std::cerr << "Error 1" << std::endl;
        return 1; // Equivalent of STOP 1 in Fortran
    }

    float c = 1.2f;
    e2(c, 3.4f);

    if (std::abs(c - 4.6f) > 0.01f) {
        std::cerr << "Error 2" << std::endl;
        return 2; // Equivalent of STOP 2 in Fortran
    }

    return 0;
}