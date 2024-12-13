// doubleNumber.cpp
#include <iostream>
#include <stdexcept>

// Function to be tested
double doubleNumber(const double x) {
    return x * 2.0;
}

// Simple assert function for the test
void assertEqual(double expected, double actual, const std::string& testName = "") {
    if (expected != actual) {
        std::cerr << "Test Failed: " << testName << " Expected " << expected << ", but got " << actual << std::endl;
        throw std::runtime_error("Test Failed: " + testName);
    } else {
        std::cout << "Test Passed: " << testName << std::endl;
    }
}

int main() {
    // Conduct the test
    try {
        assertEqual(10.0, doubleNumber(5.0), "DoubleNumber Test");
    } catch(const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return 1; // Indicate an error occurred
    }
    return 0; // Success
}