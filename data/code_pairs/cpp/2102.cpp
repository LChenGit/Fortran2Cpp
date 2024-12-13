#include <iostream>

// Function to calculate sum of first N numbers
int sumFirstNNumbers(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

// Main function with a simple test
int main() {
    int result = sumFirstNNumbers(10);
    if (result == 55) {
        std::cout << "Test passed. The sum of the first 10 numbers is " << result << std::endl;
    } else {
        std::cout << "Test failed. Result is " << result << std::endl;
    }
    return 0;
}