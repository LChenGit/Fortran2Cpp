#include <iostream>

int getA() {
    int a = 1;
    return a;
}

int main() {
    int a = getA();
    std::cout << "a = " << a << std::endl;
    return 0;
}