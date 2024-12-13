// test_subroutines.cpp
#include <iostream>

void f7(int& a, float& r) {
    a = 5;
    r = 10.0f;
}

void f9(int& i) {
    i = 1;
}

void f10(int& a, int& b) {
    a = 2;
    b = 3;
}

int main() {
    int a, b, i;
    float r;
    
    f7(a, r);
    std::cout << "f7: " << a << " " << r << std::endl;
    
    f9(i);
    std::cout << "f9: " << i << std::endl;
    
    f10(a, b);
    std::cout << "f10: " << a << " " << b << std::endl;
    
    return 0;
}