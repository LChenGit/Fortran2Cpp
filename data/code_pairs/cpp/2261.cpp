#include <iostream>
#include <cmath> // For atan function
#include <cassert> // For assertions

class Circle {
public:
    static constexpr double pi = 4.0 * std::atan(1.0);
    double radius;

    Circle() : radius(0) {} // Constructor to initialize radius to 0
};

int main() {
    Circle circle;

    // Test 1: Check the value of pi
    assert(std::abs(Circle::pi - 3.14159265358979323846) < 1.0e-6);
    std::cout << "Test 1 passed: pi is correct." << std::endl;

    // Test 2: Check the initial value of radius
    assert(circle.radius == 0.0);
    std::cout << "Test 2 passed: Initial radius is correct." << std::endl;

    // Test 3: Set and check the radius
    circle.radius = 5.0;
    assert(circle.radius == 5.0);
    std::cout << "Test 3 passed: Radius is correctly set and retrieved." << std::endl;

    return 0;
}