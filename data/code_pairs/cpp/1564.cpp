#include <iostream>

void printMessage() {
    std::cout << "This is a subroutine" << std::endl;
}

int doubleValue(int x) {
    return x * 2;
}

void testPrintMessage() {
    printMessage();
}

void testDoubleValue() {
    std::cout << doubleValue(5) << std::endl;
}

int main() {
    testPrintMessage();
    testDoubleValue();
    return 0;
}