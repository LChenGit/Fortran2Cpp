#include <iostream>

// Function declarations
int y();
int z();
int w();
int x();

// Equivalent to the Fortran module 'm1'
class m1 {
public:
    typedef int (*func_ptr)();

    static void s1(func_ptr f) {
        int result = f();
        std::cout << "Function called through s1: Result = " << result << std::endl;
    }

    static void s2(int x) {
        std::cout << "s2 called with x = " << x << std::endl;
    }
};

// Function definitions
int y() {
    return 1;
}

int z() {
    return 1;
}

int w() {
    return 1;
}

int x() {
    return 1;
}

int main() {
    m1::s1(y);
    m1::s1(z);
    m1::s1(w);
    m1::s1(x);
    
    m1::s2(x());

    std::cout << "y() = " << y() << std::endl;
    std::cout << "z() = " << z() << std::endl;
    std::cout << "w() = " << w() << std::endl;
    std::cout << "x() = " << x() << std::endl;

    return 0;
}