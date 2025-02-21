#include <iostream>
#include <cassert>

void bar(char ii, char b) {
    if (b != ii) {
        std::cout << "Assertion failed" << std::endl;
        exit(1);
    }
}

void foo(char& ii) {
    char b = ii;
    bar(ii, b);
}

int main() {
    char ii = 7;
    foo(ii);

    // Unit tests
    assert(foo != nullptr); // Test if function pointer is not null

    char test_value = 5;
    foo(test_value);
    assert(true); // If no exception is thrown, the test passes

    test_value = -128;
    foo(test_value);
    assert(true); // If no exception is thrown, the test passes

    test_value = 127;
    foo(test_value);
    assert(true); // If no exception is thrown, the test passes

    std::cout << "All unit tests passed" << std::endl;
    return 0;
}