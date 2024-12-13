#include <iostream>

struct NamelistI {
    static int ii; // Making it static to emulate Fortran's 'save' behavior
};

int NamelistI::ii = 0;

void foo() {
    NamelistI::ii++;
}

void bar() {
    NamelistI::ii++;
}

int main() {
    // Test the behavior of `foo` and `bar` with respect to the static variable
    foo();
    std::cout << "After first call to foo, NamelistI::ii = " << NamelistI::ii << std::endl;

    bar();
    std::cout << "After first call to bar, NamelistI::ii = " << NamelistI::ii << std::endl;

    foo();
    std::cout << "After second call to foo, NamelistI::ii = " << NamelistI::ii << std::endl;

    bar();
    std::cout << "After second call to bar, NamelistI::ii = " << NamelistI::ii << std::endl;

    return 0;
}