#include <iostream>
#include <cmath> // for std::abs

// Declare the function prototype
double add(double a, double b);

int main() {
    double a = 5.0;
    double b = 10.0;
    double c = add(a, b);
    std::cout << "The sum is: " << c << std::endl;
    return 0;
}

// Define the function
double add(double a, double b) {
    return a + b;
}