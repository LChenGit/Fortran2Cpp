#include <iostream>
#include <cassert>
#include <cmath>

double DQWGTC(double X, double C, double P2, double P3, double P4, int KP) {
    return 1.0 / (X - C);
}

int main() {
    // Test 1
    double result = DQWGTC(3.0, 2.0, 0.0, 0.0, 0.0, 0);
    std::cout << "DQWGTC(3.0, 2.0, 0.0, 0.0, 0.0, 0) = " << result << std::endl;
    assert(std::fabs(result - 1.0) < 1e-6);

    // Add more tests as needed
    
    std::cout << "All tests passed." << std::endl;
    return 0;
}