#include <iostream>

void foo10(float a[10][10], float b[10][10]) {
    for (int k = 1; k <= 4; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (a[i][j] < k) {
                    float temp = a[i][j] + b[i][j]; // Update value of 'a' first
                    b[i][j] = temp - b[i][j]; // Then use updated 'a' to calculate 'b'
                    a[i][j] = temp; // Assign updated value back to 'a'
                } else {
                    a[i][j] = a[i][j] * 2;
                }
            }
        }
    }
}

int main() {
    float a[10][10] = {0}, b[10][10];

    // Initialize b
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            b[i][j] = 1.0;
        }
    }

    foo10(a, b);

    // Output for inspection or perform checks
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << "a[" << i << "][" << j << "] = " << a[i][j]
                      << " b[" << i << "][" << j << "] = " << b[i][j] << std::endl;
        }
    }

    return 0;
}