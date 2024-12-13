#include <array>
#include <iostream>

int main() {
    const int n = 10, k = 3-1; // Adjusting k for zero-based indexing
    std::array<std::array<int, n>, n> y; // 2D array
    std::array<int, n> res1, res2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            y[i][j] = n * (i + 1) + (j + 1); // Correct formula for initialization
        }
    }

    res2 = y[k];
    for (int j = 3; j < n; ++j) {
        y[k][j] = y[k][j - 1];
    }
    y[k][2] = 0;
    res1 = y[k];

    y[k] = res2;
    for (int j = n-1; j >= 3; --j) {
        y[k][j] = y[k][j - 1];
    }
    y[k][2] = 0;
    res2 = y[k];

    // Check if arrays are different
    bool arrays_are_different = false;
    for (int i = 0; i < n; ++i) {
        if (res1[i] != res2[i]) {
            arrays_are_different = true;
            break;
        }
    }

    if (arrays_are_different) {
        std::cerr << "Arrays are different. Stopping." << std::endl;
        return 1; // Stop the program if arrays are different
    } else {
        std::cout << "Arrays are identical." << std::endl;
    }

    return 0; // Normal termination
}