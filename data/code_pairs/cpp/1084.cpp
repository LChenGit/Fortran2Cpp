#include <iostream>
#include <cstdlib> // For std::exit

struct MyType {
    int a, b, c;
};

int main() {
    MyType myVar;
    myVar.a = 1;
    myVar.b = 2;
    myVar.c = 3;

    if (myVar.a == 1) {
        std::cout << "Test A Passed" << std::endl;
    } else {
        std::cout << "Test A Failed" << std::endl;
    }

    if (myVar.b == 2) {
        std::cout << "Test B Passed" << std::endl;
    } else {
        std::cout << "Test B Failed" << std::endl;
    }

    if (myVar.c == 3) {
        std::cout << "Test C Passed" << std::endl;
    } else {
        std::cout << "Test C Failed" << std::endl;
    }

    return 0;
}