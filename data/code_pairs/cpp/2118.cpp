#include <iostream>
#include <cassert>
#include <functional>

// Forward declarations for functions
int y();
int z();
int w();
int x();

namespace m1 {

    typedef std::function<int()> FuncType;

    void s1(FuncType f) {
        // Demonstrates using a function passed as an argument.
    }

    void s2(int x) {
        // Demonstrates passing an integer.
    }

}

int y() {
    return 1;
}

int z() {
    return 1;
}

int x() {
    return 1;
}

int w() {
    return 1;
}

void run_tests() {
    using namespace m1;

    assert(y() == 1);
    std::cout << "Test y() passed" << std::endl;
    
    assert(z() == 1);
    std::cout << "Test z() passed" << std::endl;

    assert(w() == 1);
    std::cout << "Test w() passed" << std::endl;

    assert(x() == 1);
    std::cout << "Test x() passed" << std::endl;

    s1(y);
    s1(z);
    s1(w);
    s1(x);
    s2(x());

    std::cout << "All tests passed." << std::endl;
}

int main() {
    run_tests();
    return 0;
}