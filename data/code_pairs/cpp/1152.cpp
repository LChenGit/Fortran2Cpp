#include <iostream>
#include <cstdlib>

int f_static_a = 0; // Declared globally to mimic Fortran's SAVE attribute

int f(int x) {
    f_static_a += x;
    return f_static_a;
}

void assert_test(const char* s, int i1, int i2) {
    if (i1 != i2) {
        std::cout << s << ": expected " << i2 << " but was " << i1 << std::endl;
        std::exit(1);
    }
}

void test_f() {
    f_static_a = 0; // Resetting the state for f
    assert_test("f()", f(3), 3);
    assert_test("f()", f(4), 7);
    assert_test("f()", f(2), 9);
}

int main() {
    test_f();

    std::cout << "All tests passed." << std::endl;
    return 0;
}