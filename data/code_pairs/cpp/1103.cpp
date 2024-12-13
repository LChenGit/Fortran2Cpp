// rsc.cpp
#include <cstdint>
#include <iostream>
#include <cmath>

double rsc(int32_t K, int32_t NA, double EA, int32_t NB, double EB, int32_t NC, double EC, int32_t ND, double ED) {
    return (EA + EB + EC + ED) / 4.0 * (K + NA + NB + NC + ND);
}

void testRscFunction() {
    int32_t K = 1, NA = 2, NB = 3, NC = 4, ND = 5;
    double EA = 3.0, EB = 4.0, EC = 5.0, ED = 6.0;
    double expected = ((EA + EB + EC + ED) / 4.0) * (K + NA + NB + NC + ND);
    double result = rsc(K, NA, EA, NB, EB, NC, EC, ND, ED);
    
    if (std::abs(result - expected) < 1e-6) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed: Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    testRscFunction();
    return 0;
}