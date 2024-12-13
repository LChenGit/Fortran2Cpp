#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

double VP(double T) {
    double TT = T + 273.16;
    return pow(10.0, 22.5518 - (2937.4 / TT) - 4.9283 * log10(TT)) * 10.0;
}

void testVP(const std::vector<std::pair<double, double>>& testCases) {
    for (const auto& testCase : testCases) {
        double T = testCase.first;
        double result = VP(T);
        std::cout << "VP(" << T << ") = " << result << std::endl;
    }
}

int main() {
    // Test cases
    std::vector<std::pair<double, double>> testCases = {
        {25.0, 32.0047}, // Expected results based on Fortran output
        {50.0, 124.458},
        {100.0, 1011.67}
    };

    testVP(testCases);

    return 0;
}