#include <iostream>

// Declaration of great_rsd in C++
void great_rsd(int a, int b) {
    std::cout << "Sum of " << a << " and " << b << " is " << (a + b) << std::endl;
}

// Main function to run test cases
int main() {
    // Test cases for the great_rsd function
    great_rsd(1, 2);
    great_rsd(-1, -2);
    great_rsd(100, 200);

    return 0;
}