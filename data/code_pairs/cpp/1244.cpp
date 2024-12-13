#include <iostream>
#include <cmath>

int main() {
    float x = 1.234E4f; // Using 'f' to ensure it's a float
    std::cout << std::trunc(x) << std::endl;
    return 0;
}