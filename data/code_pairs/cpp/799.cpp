#include <iostream>
#include <array>

int main() {
    std::array<std::array<int, 3>, 3> a{}; // Zero-initialized

    for (int l = 0; l < 3; ++l) {
        for (int ll = 0; ll < 3; ++ll) {
            a[l][ll] = 2;
        }
    }

    for (const auto& row : a) {
        for (int elem : row) {
            if (elem != 2) {
                std::cerr << "An element not equal to 2 was found." << std::endl;
                return 1; // Exit the program with an error code
            }
        }
    }

    return 0; // Successful completion
}