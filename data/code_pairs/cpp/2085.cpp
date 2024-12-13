// main.cpp
#include <iostream>
#include <array>

int main() {
    std::array<float, 3> vector3d = {1.0f, 2.0f, 3.0f};
    std::array<std::array<float, 3>, 3> matrix3d;

    // Initialize the matrix with 1.0f
    for (auto &row : matrix3d) {
        row.fill(1.0f);
    }

    // Printing vector for manual verification
    std::cout << "Vector3d:" << std::endl;
    for (const auto &value : vector3d) {
        std::cout << value << std::endl;
    }

    // Printing matrix for manual verification
    std::cout << "Matrix3d:" << std::endl;
    for (const auto &row : matrix3d) {
        for (const auto &value : row) {
            std::cout << value << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}