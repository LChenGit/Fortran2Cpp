#include <iostream>

void s() {
    std::cout << "s called" << std::endl;
}

void t() {
    s();
}

int main() {
    s(); // Directly calling s
    t(); // Calling t, which in turn calls s
    return 0;
}