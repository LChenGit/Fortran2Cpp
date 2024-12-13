// main.cpp
#include <iostream>
#include <string>

void test_conversion(int& i, float& x, std::string& str) {
    i = 42;
    x = 3.14f;
    str = "Hello";
}

int main() {
    int i;
    float x;
    std::string str;

    test_conversion(i, x, str);

    std::cout << "Integer i = " << i << std::endl;
    std::cout << "Real x = " << x << std::endl;
    std::cout << "String str = " << str << std::endl;

    if (i == 42) {
        std::cout << "Test i passed" << std::endl;
    } else {
        std::cout << "Test i failed" << std::endl;
    }

    if (x == 3.14f) {
        std::cout << "Test x passed" << std::endl;
    } else {
        std::cout << "Test x failed" << std::endl;
    }

    if (str == "Hello") {
        std::cout << "Test str passed" << std::endl;
    } else {
        std::cout << "Test str failed" << std::endl;
    }

    return 0;
}