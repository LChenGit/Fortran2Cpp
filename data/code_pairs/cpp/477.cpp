#include <iostream>

int main() {
    int i = 1 >> 3; // Right shift the bits of 1 by 3 positions
    std::cout << "Result of shifting 1 by 3 positions to the right: " << i << std::endl;
    return 0;
}