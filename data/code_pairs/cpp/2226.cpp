#include <iostream>
#include <cassert>

double cvmgp(double x1, double x2, int x3) {
    return (x3 < 0) ? x2 : x1;
}

double cvmgz(double x1, double x2, int x3) {
    return (x3 < 0) ? x2 : x1;
}

double cvmgn(double x1, double x2, int x3) {
    return (x3 <= 0) ? x1 : x2;
}

double cvmgt(double x1, double x2, bool x3) {
    return x3 ? x1 : x2;
}

double cvmgm(double x1, double x2, int x3) {
    return (x3 <= 0) ? x2 : x1;
}

void test_functions() {
    assert(cvmgp(1.0, 2.0, -1) == 2.0);
    assert(cvmgp(1.0, 2.0, 1) == 1.0);

    assert(cvmgz(1.0, 2.0, -1) == 2.0);
    assert(cvmgz(1.0, 2.0, 1) == 1.0);

    assert(cvmgn(1.0, 2.0, -1) == 1.0);
    assert(cvmgn(1.0, 2.0, 1) == 2.0);

    assert(cvmgt(1.0, 2.0, true) == 1.0);
    assert(cvmgt(1.0, 2.0, false) == 2.0);

    assert(cvmgm(1.0, 2.0, -1) == 2.0);
    assert(cvmgm(1.0, 2.0, 1) == 1.0);

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_functions();
    return 0;
}