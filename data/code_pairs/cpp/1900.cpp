#include <iostream>

// Declaration of the add function
int add(int a, int b) {
    return a + b;
}

// Main function to test the add function
int main() {
    int result = add(2, 3);
    
    std::cout << "The sum of 2 and 3 is " << result << std::endl;
    return 0;
}