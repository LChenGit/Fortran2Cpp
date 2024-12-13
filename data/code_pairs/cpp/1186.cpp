#include <iostream>

// Function prototype
int add(int a, int b);

int main() {
    int result = add(2, 3);
    std::cout << "Result of adding 2 and 3 is " << result << std::endl;
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}