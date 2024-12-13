#include <iostream>

int factorial(int n) {
    if (n <= 1) return 1;
    else return n * factorial(n - 1);
}

int main() {
    int n;
    std::cout << "Enter a number:" << std::endl;
    std::cin >> n;
    std::cout << "Factorial is: " << factorial(n) << std::endl;
    return 0;
}