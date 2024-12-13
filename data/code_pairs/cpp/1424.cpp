#include <iostream>

float f(float x) {
    x = 1;
    return x;
}

int main() {
    float a, b;
    a = 2;
    b = f(a);
    std::cout << "b = " << b << std::endl;
    return 0;
}