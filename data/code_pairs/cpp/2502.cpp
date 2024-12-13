#include <iostream>

class A {
public:
    void b() {
        std::cout << "Subroutine b called" << std::endl;
    }
};

int main() {
    A a;
    a.b();
    return 0;
}