#include <complex>
#include <cassert>
#include <iostream>

class basics_t {
public:
    int i;
    float r;
    std::complex<float> c;

    basics_t(int i = 42, float r = 0.0f, std::complex<float> c = {0.0f, 1.0f})
        : i(i), r(r), c(c) {}
};

void test_basics(const basics_t &basics) {
    assert(basics.i == 42);
    assert(basics.r == 0.0f);
    assert(basics.c == std::complex<float>(0.0f, 1.0f));
    std::cout << "C++ tests completed successfully." << std::endl;
}

int main() {
    basics_t basics;
    test_basics(basics);

    // Additional test for constructor with custom arguments
    basics_t basics_custom(42, 0.0f, {0.0f, 1.0f});
    test_basics(basics_custom);

    return 0;
}