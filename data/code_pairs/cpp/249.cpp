#include <iostream>
#include <cmath> // For std::isnan

void IARNAN(double NUM, int& INFO) {
    INFO = 0;
    if (std::isnan(NUM)) {
        INFO = 1;
    }
}

void testIARNAN(double num, int expected, const std::string& testName) {
    int info = 0;
    IARNAN(num, info);
    std::cout << testName << ": ";
    if (info == expected) {
        std::cout << "Passed." << std::endl;
    } else {
        std::cout << "Failed. Expected INFO=" << expected << ", Got INFO=" << info << std::endl;
    }
}

int main() {
    // Test with a normal number
    testIARNAN(1.0, 0, "Test with normal number");

    // Test with NaN
    double nanValue = std::nan("1");
    testIARNAN(nanValue, 1, "Test with NaN");

    return 0;
}