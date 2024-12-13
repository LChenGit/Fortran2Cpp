#include <iostream>
#include <cmath> // For std::abs

// The translated function
void floop8_F77(int N, float* a, float* x, float u) {
    for (int i = 0; i < N; i++) {
        x[i] = u / a[i];
    }
}

int main() {
    const int N = 5;
    float a[N] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float x[N]; // Output array
    float u = 10.0;

    floop8_F77(N, a, x, u);

    std::cout << "Testing floop8_F77..." << std::endl;
    bool testPassed = true;
    for (int i = 0; i < N; i++) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
        if (std::abs(x[i] - (u / a[i])) > 1E-6) {
            std::cout << "Test failed." << std::endl;
            testPassed = false;
            break;
        }
    }
    if(testPassed) {
        std::cout << "Test passed." << std::endl;
    }

    return 0;
}