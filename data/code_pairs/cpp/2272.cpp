#include <iostream>
#include <array>
#include <cassert>

void foo(std::array<std::array<int, 4>, 4>& a, int i) {
    bool condition = false;
    for (int j = 0; j < 3; ++j) {
        if (a[i + 1][j] != 0) {
            condition = true;
            break;
        }
    }

    if (condition) {
        for (int j = 1; j < 4; ++j) {
            a[i + 2][j] = 1;
        }
    }
}

int main() {
    std::array<std::array<int, 4>, 4> a = {{{0}}};
    int i = 0;
    a[1][0] = 1;  // Set condition for modification

    foo(a, i);

    // Expected result
    std::array<std::array<int, 4>, 4> expected = {{{0}}};
    expected[1][0] = 1; // Input condition
    expected[2][1] = 1; // Modified by function
    expected[2][2] = 1; // Modified by function
    expected[2][3] = 1; // Modified by function

    assert(a == expected);

    std::cout << "Modified array a:" << std::endl;
    for (const auto& row : a) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Test passed!" << std::endl;

    return 0;
}