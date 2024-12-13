#include <iostream>

void func2();

float mainLogic() {
    float x = 1.0f;
    std::cout << "x in main before func2: " << x << std::endl;
    func2();
    std::cout << "x in main after func2: " << x << std::endl;
    return x; // Return x for testing purposes, though not used here.
}

void func2() {
    char x = 'A';
    std::cout << "x in func2: " << x << std::endl;
}

int main() {
    mainLogic();
    return 0;
}