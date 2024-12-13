#include <iostream>
#include <cmath>

bool SB02MR(double REIG, double IEIG) {
    const double ZERO = 0.0;
    return REIG >= ZERO;
}

void assertTest(bool condition, const std::string& message) {
    if (!condition) {
        std::cout << "Assertion failed: " << message << std::endl;
    } else {
        std::cout << "Test passed." << std::endl;
    }
}

int main() {
    assertTest(SB02MR(1.0, 2.0), "Test with positive REIG failed.");
    assertTest(SB02MR(0.0, 2.0), "Test with zero REIG failed.");
    assertTest(!SB02MR(-1.0, 2.0), "Test with negative REIG failed.");

    return 0;
}