#include <iostream>
#include <cstdlib>

int main() {
    int x[100][100] = {0}, y[100][100] = {0}; // Initialize arrays
    int result = 0;

    // Set the interior of x to 1
    for (int i = 1; i < 99; ++i) {
        for (int j = 1; j < 99; ++j) {
            x[i][j] = 1;
        }
    }

    // Initialize y's columns to 0, then set the interior to 1
    for (int j = 0; j < 100; ++j) {
        for (int i = 0; i < 100; ++i) {
            y[i][j] = 0;
        }
    }
    for (int i = 1; i < 99; ++i) {
        for (int j = 1; j < 99; ++j) {
            y[i][j] = 1;
        }
    }

    // Compare x and y
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            if (x[i][j] != y[i][j]) {
                result = -1;
            }
        }
    }

    // Check result and print message
    if (result != 0) {
        std::cout << "ERROR" << std::endl;
    } else {
        std::cout << "PASS" << std::endl;
    }

    return 0;
}