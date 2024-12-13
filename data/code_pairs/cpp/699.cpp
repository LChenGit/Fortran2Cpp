#include <iostream>

// Function to calculate the square of a number
int square(int n) {
    return n * n;
}

int main() {
    int number = 4;
    int result = square(number);
    
    // Test and print the result
    std::cout << "The square of " << number << " is " << result << std::endl;
    
    return 0;
}