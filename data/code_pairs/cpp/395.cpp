// hello.cpp
#include <iostream>

void greet();
void performCalculation();

int main() {
    greet();
    performCalculation();
    return 0;
}

void greet() {
    std::cout << "Hello, World!" << std::endl;
}

void performCalculation() {
    // This function calculates the sum of 3 and 4 and prints the result.
    int result = 3 + 4;
    std::cout << "The sum of 3 and 4 is " << result << "." << std::endl;
}