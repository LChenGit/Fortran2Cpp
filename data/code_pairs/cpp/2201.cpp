#include <iostream>
#include <array>
#include <cassert>

// Function to be tested
void initializeArray(std::array<std::array<float, 16>, 16>& a2) {
    for(int j = 0; j < 16; ++j) {
        for(int i = 0; i < 16; ++i) {
            a2[i][j] = 0.0f;
        }
    }
}

int main() {
    // Declare a 2D array with dimensions 16x16
    std::array<std::array<float, 16>, 16> a2;

    // Initialize the array
    initializeArray(a2);

    // Check if all elements are zero
    bool pass = true;
    for(int j = 0; j < 16; ++j) {
        for(int i = 0; i < 16; ++i) {
            if (a2[i][j] != 0.0f) {
                pass = false;
                break;
            }
        }
        if (!pass) break;
    }

    // Output the result
    if (pass) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "FAIL" << std::endl;
    }

    // Assert to ensure correctness in automated tests
    assert(pass);

    return 0;
}