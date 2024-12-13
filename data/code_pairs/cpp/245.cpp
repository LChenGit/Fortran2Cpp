#include <iostream>

// Function to calculate the square of a number
float square(float x) {
    return x * x;
}

int main() {
    // Set a test value
    float test_value = 4.0;
    // Calculate the square
    float squared_value = square(test_value);
    // Output the result
    std::cout << "The square of " << test_value << " is " << squared_value << std::endl;
    return 0;
}