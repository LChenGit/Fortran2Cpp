#include <array>
#include <iostream>

void iau_CP(const std::array<double, 3>& P, std::array<double, 3>& C) {
    for (int i = 0; i < 3; ++i) {
        C[i] = P[i];
    }
}

int main() {
    std::array<double, 3> P = {1.0, 2.0, 3.0};
    std::array<double, 3> C;

    // Call the function
    iau_CP(P, C);

    // Check if C is a copy of P
    bool success = true;
    for (int i = 0; i < 3; ++i) {
        if (C[i] != P[i]) {
            success = false;
            break;
        }
    }

    if (success) {
        std::cout << "Test Passed: C is a copy of P." << std::endl;
    } else {
        std::cout << "Test Failed: C is not a copy of P." << std::endl;
    }

    return 0;
}