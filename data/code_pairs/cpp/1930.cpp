#include <iostream>
#include <cstdlib>

namespace a {
    double d(double i) { return 1.0; }
    double c(int j) { return 2.0; }
    double e(double i) { return 3.0; }
    double f(int j) { return 4.0; }
}

int main() {
    using namespace a;

    if (d(1.0) != 1.0) {
        std::cerr << "Test d failed" << std::endl;
        std::abort();
    }

    if (c(1) != 2.0) {
        std::cerr << "Test c failed" << std::endl;
        std::abort();
    }

    if (e(1.0) != 3.0) {
        std::cerr << "Test e failed" << std::endl;
        std::abort();
    }

    if (f(1) != 4.0) {
        std::cerr << "Test f failed" << std::endl;
        std::abort();
    }

    std::cout << "All C++ tests passed." << std::endl;

    return 0;
}