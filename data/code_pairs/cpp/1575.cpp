#include <iostream>
#include <array>

int main() {
    std::array<int, 12> A, C;

    // Initialize A with values 1 to 12
    for (int i = 0; i < 12; ++i) {
        A[i] = i + 1;
    }

    // Increment each element by 1 and assign to C
    for (int i = 0; i < 12; ++i) {
        C[i] = A[i] + 1;
    }

    // Print elements of C
    for (int i = 0; i < 12; ++i) {
        std::cout << "C[" << i << "] = " << C[i] << std::endl;
    }

    return 0;
}