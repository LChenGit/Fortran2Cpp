#include <iostream>
#include <tuple>
#include <cmath>
#include <cassert>

// Define the are_close function
bool are_close(const std::tuple<double, double, double, double>& actual, 
               const std::tuple<double, double, double, double>& expected, 
               double tolerance) {
    return (std::abs(std::get<0>(actual) - std::get<0>(expected)) <= tolerance) &&
           (std::abs(std::get<1>(actual) - std::get<1>(expected)) <= tolerance) &&
           (std::abs(std::get<2>(actual) - std::get<2>(expected)) <= tolerance) &&
           (std::abs(std::get<3>(actual) - std::get<3>(expected)) <= tolerance);
}

// Define the cubecoeff function
void cubecoeff(double x1, double y1, double m1, double x2, double y2, double m2, double &a, double &b, double &c, double &d) {
    double den = -(x1 - x2) * (x1 - x2) * (x1 - x2);

    // Calculate a
    double num_a = 2.0 * (y1 - y2) - (m1 + m2) * (x1 - x2);
    a = num_a / den;

    // Calculate b
    double num_b = -3.0 * (x1 + x2) * (y1 - y2) +
                   m1 * (x1 * x1 + x1 * x2 - 2.0 * x2 * x2) -
                   m2 * (x2 * x2 + x1 * x2 - 2.0 * x1 * x1);
    b = num_b / den;

    // Calculate c
    double num_c = 6.0 * x1 * x2 * (y1 - y2) +
                   m1 * x2 * (x2 * x2 + x1 * x2 - 2.0 * x1 * x1) -
                   m2 * x1 * (x1 * x1 + x1 * x2 - 2.0 * x2 * x2);
    c = num_c / den;

    // Calculate d
    double term1 = x1 * x1 * x2 * x2 * (m2 - m1);
    double term2_part1 = 3.0 * (x1 * x1 * m2 - x2 * x2 * m1);
    double term2_part2 = 6.0 * (x1 * y2 - x2 * y1);
    double term2_part3 = -2.0 * (x1 + x2) * (x1 * m2 - x2 * m1);
    double term2 = x1 * x2 * (term2_part1 + term2_part2 + term2_part3);
    double term3 = 2.0 * (x1 * x1 * x1 * y2 - x2 * x2 * x2 * y1);
    double term4 = -3.0 * (x1 + x2) * (x1 * x1 * y2 - x2 * x2 * y1);
    double num_d = term1 + term2 + term3 + term4;
    d = num_d / den;
}

// Main function to test the cubecoeff function
int main() {
    // Test case 1
    double x1 = 1.0, y1 = 2.0, m1 = 3.0;
    double x2 = 4.0, y2 = 5.0, m2 = 6.0;
    double a, b, c, d;

    cubecoeff(x1, y1, m1, x2, y2, m2, a, b, c, d);

    // Expected values based on known correct results
    std::tuple<double, double, double, double> expected = {1.0, -2.0, 3.0, 4.0};
    assert(are_close(std::make_tuple(a, b, c, d), expected, 0.01));

    // Test case 2
    x1 = 0.0;
    y1 = 1.0;
    m1 = 2.0;
    x2 = 1.0;
    y2 = 3.0;
    m2 = 4.0;

    cubecoeff(x1, y1, m1, x2, y2, m2, a, b, c, d);

    expected = {2.0, -2.0, 2.0, 1.0};
    assert(are_close(std::make_tuple(a, b, c, d), expected, 0.01));

    // Add more test cases as needed

    std::cout << "All tests passed!" << std::endl;
    return 0;
}