#include <iostream>
#include <vector>
#include <cassert>

void V7CPY(int P, std::vector<float>& Y, const std::vector<float>& X) {
    for (int i = 0; i < P; ++i) {
        Y[i] = X[i];
    }
}

int main() {
    int P = 5;
    std::vector<float> X(P), Y(P, 0); // Initialize X with test data and Y with zeros

    // Initialize X with test data
    for (int i = 0; i < P; ++i) {
        X[i] = i + 1; // +1 because we're simulating 1-based indexing for comparison with Fortran
    }

    // Call V7CPY to copy X to Y
    V7CPY(P, Y, X);

    // Check results
    for (int i = 0; i < P; ++i) {
        assert(Y[i] == X[i]); // This will terminate the program if the condition is false
    }

    std::cout << "Test Passed: All elements copied correctly." << std::endl;

    return 0;
}