#include <iostream>
#include <cmath> // For std::abs

float DM3(float x) {
    float M2m, M2;

    if (x >= 0.0f && x <= 2.0f) {
        M2m = 1.0f - std::abs(x - 1.0f);
    } else {
        M2m = 0.0f;
    }

    if (x >= 1.0f && x <= 3.0f) {
        M2 = 1.0f - std::abs(x - 2.0f);
    } else {
        M2 = 0.0f;
    }

    return M2m - M2;
}

void testDM3(float x, float expected) {
    float result = DM3(x);
    std::cout << "Test (x=" << x << "): Expected: " << expected << ", Got: " << result << std::endl;
}

int main() {
    testDM3(0.5f, 0.5f);
    testDM3(1.5f, 0.0f);
    testDM3(2.5f, -0.5f);

    return 0;
}