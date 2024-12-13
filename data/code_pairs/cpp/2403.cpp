// translation.cpp
#include <iostream>
#include <memory>

class T0 {
public:
    int j;
    T0() : j(42) {}
};

class T {
public:
    int i;
    std::unique_ptr<T0> foo;

    T() : i(0), foo(nullptr) {}
};

int main() {
    T m;
    m.foo = std::make_unique<T0>();
    m.i = 5;

    if (m.foo) {
        T0 &bar = *m.foo;
        std::cout << "C++ test: bar.j = " << bar.j << std::endl;
    }

    return 0;
}