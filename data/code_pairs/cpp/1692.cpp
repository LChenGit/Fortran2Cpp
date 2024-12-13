#include <iostream>
#include <array>

int main() {
    std::array<int, 5> a = {1, 2, 3, 4, 5};

    for (auto& value : a) {
        if (value == 2) {
            value *= 2;  // Multiply by 2
        } else {
            value *= 3;  // Multiply by 3
        }
    }

    for (const auto& value : a) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}