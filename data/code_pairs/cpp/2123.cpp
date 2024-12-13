// File: test_foo.cpp
#include <iostream>

void foo();

int main() {
    foo(); // First call to foo
    foo(); // Second call to foo
    return 0;
}

void foo() {
    static int i = 0; // 'static' ensures 'i' retains its value between calls.
    std::cout << "Value of i before assignment: " << i << std::endl;
    i = 1;
    std::cout << "Value of i after assignment: " << i << std::endl;
}