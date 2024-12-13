// rk4.cpp & rk4_test.cpp
#include <iostream>
#include <cmath> // For fabs (if needed for more complex tests)

double rk4_int(double rhsInit, double dTime) {
    double k1, k2, k3, k4;

    k1 = rhsInit;
    k2 = rhsInit + (dTime / 2.0) * k1;
    k3 = rhsInit + (dTime / 2.0) * k2;
    k4 = rhsInit + dTime * k3;

    return rhsInit + (dTime / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
}

// This function acts as a simple test for our RK4 implementation.
void test_rk4_int() {
    double result = rk4_int(1.0, 0.1);
    std::cout << "C++ Test Result: " << result << std::endl;
    // For a more rigorous test, consider using a testing framework like Google Test.
    // This example uses a simple console output for demonstration purposes.
}

int main() {
    test_rk4_int();
    return 0;
}