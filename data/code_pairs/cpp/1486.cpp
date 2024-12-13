#include <iostream>
#include <vector>
#include <cmath> // For fabs

void per_freq(std::vector<float>& f, int n, const std::vector<double>& flim) {
    if (n <= 0 || flim.size() != 2) {
        return;
    }

    f.resize(n);
    double df = (flim[1] - flim[0]) / static_cast<double>(n - 1);

    for (int i = 0; i < n; ++i) {
        f[i] = static_cast<float>(flim[0] + static_cast<double>(i) * df);
    }
}

void testPerFreq() {
    int n = 5;
    std::vector<double> flim = {100.0, 200.0};
    std::vector<float> f;
    per_freq(f, n, flim);

    std::vector<float> expected_f = {100.0f, 125.0f, 150.0f, 175.0f, 200.0f};
    bool testPassed = true;

    for (int i = 0; i < n; ++i) {
        if (fabs(expected_f[i] - f[i]) > 0.001) {
            std::cout << "Test Failed at index " << i << ": Expected " << expected_f[i] << ", got " << f[i] << std::endl;
            testPassed = false;
            break;
        }
    }

    if (testPassed) {
        std::cout << "Test Passed: Frequency values are calculated correctly." << std::endl;
    }
}

int main() {
    testPerFreq(); // Run the test for per_freq function
    return 0;
}