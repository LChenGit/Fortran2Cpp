#include <iostream>
#include <complex>
#include <cstdlib> // for std::abort and EXIT_SUCCESS

void foo(std::complex<double> p[10]) {
    for (int i = 0; i < 10; ++i) {
        if (p[i] != std::complex<double>(-0.2, 0.1)) {
            std::abort();
        }
    }
}

void test_foo() {
    std::complex<double> p_test[10];
    std::complex<double> expected(-0.2, 0.1);

    for (int i = 0; i < 10; ++i) {
        p_test[i] = std::complex<double>(0.1, 0.2);
    }

    std::complex<double> multiplier(0.0, 1.0);
    for (int i = 0; i < 10; ++i) {
        p_test[i] *= multiplier;
    }

    for (int i = 0; i < 10; ++i) {
        if (p_test[i] != expected) {
            std::cout << "Test Failed!" << std::endl;
            std::abort();
        }
    }

    std::cout << "Test Passed!" << std::endl;
}

int main() {
    std::complex<double> p[10];
    for (int i = 0; i < 10; ++i) {
        p[i] = std::complex<double>(0.1, 0.2);
    }
    std::complex<double> multiplier(0.0, 1.0);
    for (int i = 0; i < 10; ++i) {
        p[i] *= multiplier;
    }
    foo(p);
    test_foo(); // Run the test function
    return EXIT_SUCCESS;
}