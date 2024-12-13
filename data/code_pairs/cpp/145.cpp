#include <iostream>
#include <array>
#include <cassert>

// Equivalent of Fortran module eq with equivalence and common block
namespace eq {
    struct A {
        std::array<int, 2> a;
    } common_a;

    int& n1 = common_a.a[0];
    int& n2 = common_a.a[1];
}

// Equivalent of Fortran module m
namespace m {
    struct t {
        int i;
    };
}

// Equivalent of Fortran module p
namespace p {
    int d(int h) {
        return h;
    }
}

// Equivalent of Fortran module q
namespace q {
    int d(int h) {
        return h;
    }
}

// Equivalent of Fortran module r
namespace r {
    int d(int h) {
        return h;
    }
}

int main() {
    // Test equivalence and common block behavior
    eq::n1 = 5;
    eq::n2 = 10;
    std::cout << "Before: n1 = " << eq::n1 << ", n2 = " << eq::n2 << std::endl;

    // Test pure functions
    int h = 10;
    std::cout << "Function d result (p context): " << p::d(h) << std::endl;
    std::cout << "Function d result (q context): " << q::d(h) << std::endl;
    std::cout << "Function d result (r context): " << r::d(h) << std::endl;

    // Change values to demonstrate equivalence
    eq::common_a.a[0] = 5;
    eq::common_a.a[1] = 10;
    std::cout << "After: n1 = " << eq::n1 << ", n2 = " << eq::n2 << std::endl;

    return 0;
}