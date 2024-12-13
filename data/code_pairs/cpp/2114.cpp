#include <iostream>

// Function prototype
void add_integers(int a, int b, int& result);

// Main function to run the test
int main() {
    int result;
    add_integers(5, 10, result);
    std::cout << "The result of adding 5 and 10 is " << result << std::endl;
    return 0;
}

// Function definition
void add_integers(int a, int b, int& result) {
    result = a + b;
}