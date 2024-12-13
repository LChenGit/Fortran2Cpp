#include <iostream>

int main() {
    const int X[3] = {5, 5, 5}; // Initialize all elements to 5

    switch (X[0]) { // Note: C++ arrays are 0-indexed
        case 1:
            std::cout << "HI" << std::endl;
            break;
        default:
            std::cout << "BYE" << std::endl;
            break;
    }

    return 0;
}