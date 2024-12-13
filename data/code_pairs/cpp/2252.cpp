#include <iostream>

// Function declarations
void greet();
void performCalculation();
int addNumbers(int a, int b);

int main() {
    greet();
    performCalculation();
    return 0;
}

// Function definitions
void greet() {
    std::cout << "Hello, World!" << std::endl;
}

void performCalculation() {
    int a = 5;
    int b = 10;
    std::cout << "The sum of 5 and 10 is: " << addNumbers(a, b) << std::endl;
}

int addNumbers(int a, int b) {
    return a + b;
}