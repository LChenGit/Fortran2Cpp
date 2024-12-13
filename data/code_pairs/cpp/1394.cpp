#include <iostream>
#include <cassert>

namespace cdat {
    double al;
    double beta;
}

void init_pars() {
    cdat::al = 16.0;
    cdat::beta = 128.0;
}

void test_init_pars() {
    init_pars(); // Initialize the parameters

    assert(cdat::al == 16.0 && "al should be initialized to 16.0");
    assert(cdat::beta == 128.0 && "beta should be initialized to 128.0");

    std::cout << "All tests passed." << std::endl;
}

int main() {
    test_init_pars(); // Run the test
    return 0;
}