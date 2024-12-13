#include <iostream>
#include <array>

int main() {
    std::array<int, 5> a = {1, 2, 3, 4, 5};
    std::array<int, 5> b = {0, 0, 0, 0, 0};

    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != 1) {
            b[i] = 2;
        }
    }

    std::cout << "b = { ";
    for (const auto& val : b) {
        std::cout << val << " ";
    }
    std::cout << "}" << std::endl;

    return 0;
}