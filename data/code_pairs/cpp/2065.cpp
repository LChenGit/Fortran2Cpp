#include <iostream>
#include <string>

// Translated function
std::string S(int X, float Y) {
    return "X = " + std::to_string(X) + " Y = " + std::to_string(Y);
}

// Demonstrating the function in a simple main program
int main() {
    std::cout << S(1, 2.0f) << std::endl;
    std::cout << S(1, 2.2f) << std::endl;

    return 0;
}