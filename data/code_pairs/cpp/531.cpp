#include <cmath>
#include <iostream>

double ZABS(double ZR, double ZI) {
    double U, V, Q, S;
    U = std::abs(ZR);
    V = std::abs(ZI);
    S = U + V;
    
    if (S == 0.0) {
        return 0.0;
    }
    
    if (U > V) {
        Q = U / V;
        return V * std::sqrt(1.0 + Q * Q);
    } else {
        Q = V / U;
        return U * std::sqrt(1.0 + Q * Q);
    }
}

// Test function
void testZABS(double ZR, double ZI, double expected) {
    double result = ZABS(ZR, ZI);
    if (std::abs(result - expected) > 1e-6) {
        std::cout << "Test failed: ZABS(" << ZR << ", " << ZI << ") = "
                  << result << "; expected " << expected << std::endl;
    } else {
        std::cout << "Test passed: ZABS(" << ZR << ", " << ZI << ") = "
                  << result << std::endl;
    }
}

int main() {
    // Test cases
    testZABS(3.0, 4.0, 5.0); // Should pass
    testZABS(5.0, 12.0, 13.0); // Should pass
    testZABS(0.0, 0.0, 0.0); // Should pass

    return 0;
}