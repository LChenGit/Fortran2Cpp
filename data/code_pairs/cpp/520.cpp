#include <iostream>

void sayHello() {
    std::cout << " Hello, World!" << std::endl; // Notice the leading space to match Fortran's output
}

void sayGoodbye() {
    std::cout << " Goodbye, World!" << std::endl; // Notice the leading space
}

int main() {
    sayHello();
    sayGoodbye();
    return 0;
}