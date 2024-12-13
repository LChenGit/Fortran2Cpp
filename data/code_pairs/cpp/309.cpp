#include <cmath>
#include <algorithm>
#include <iostream>

float SLAPY3(float X, float Y, float Z) {
    const float ZERO = 0.0f;
    float W, XABS, YABS, ZABS;

    XABS = std::abs(X);
    YABS = std::abs(Y);
    ZABS = std::abs(Z);
    W = std::max({XABS, YABS, ZABS}); // Using initializer list to compare three values

    if (W == ZERO) {
        return XABS + YABS + ZABS;
    } else {
        return W * std::sqrt((XABS / W) * (XABS / W) + (YABS / W) * (YABS / W) +
                             (ZABS / W) * (ZABS / W));
    }
}

int main() {
    // Example usage:
    std::cout << "Test 1 (All zeros): " << SLAPY3(0.0f, 0.0f, 0.0f) << std::endl;
    std::cout << "Test 2 (Positive numbers): " << SLAPY3(3.0f, 4.0f, 5.0f) << std::endl;
    std::cout << "Test 3 (Negative numbers): " << SLAPY3(-3.0f, -4.0f, -5.0f) << std::endl;
    std::cout << "Test 4 (Mix of positive and negative): " << SLAPY3(-3.0f, 4.0f, -5.0f) << std::endl;
    return 0;
}