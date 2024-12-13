#include <iostream>
#include <cmath>

int PT2SAM(float PT, int BITS);

int main() {
    // Test case 1
    std::cout << "Test 1: Expected 192, Got " << PT2SAM(0.5, 8) << std::endl;

    // Test case 2
    std::cout << "Test 2: Expected -16384, Got " << PT2SAM(-0.5, 16) << std::endl;

    // Test case 3
    std::cout << "Test 3: Expected 255, Got " << PT2SAM(2.0, 8) << std::endl;  // This should get normalized to 1.0

    return 0;
}

int PT2SAM(float PT, int BITS) {
    if (std::abs(PT) > 1.0) {
        PT = PT / std::abs(PT);
    }

    if (BITS != 8) {
        return static_cast<int>(PT * (std::pow(2, BITS - 1) - 1) + 0.5);
    } else {
        return static_cast<int>((PT * 0.5 + 0.5) * (std::pow(2, BITS) - 1) + 0.5);
    }
}