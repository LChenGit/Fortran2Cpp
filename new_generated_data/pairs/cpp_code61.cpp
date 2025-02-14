#include <iostream>
#include <vector>
#include <cmath>

void numericalFunction(std::vector<double>& a) {
    for (size_t j = 0; j < a.size(); ++j) {
        a[j] = 5.0 - 0.1 * static_cast<double>(j + 1);
    }
}

int main() {
    const int n = 10;
    std::vector<double> actual(n, 1.0);
    std::vector<double> expected(n);
    
    for (int i = 0; i < n; ++i) {
        expected[i] = 5.0 - 0.1 * static_cast<double>(i + 1);
    }
    
    numericalFunction(actual);
    
    bool allPass = true;
    const double tolerance = 0.0001;
    
    std::cout << "C++ Output:
";
    std::cout << "Index | Actual | Expected | Pass
";
    
    for (int i = 0; i < n; ++i) {
        if (std::abs(actual[i] - expected[i]) > tolerance) {
            allPass = false;
        }
        std::cout << (i + 1) << " | " << actual[i] 
                  << " | " << expected[i]
                  << " | " << (allPass ? "Yes" : "No") << "
";
    }
    
    std::cout << "
Test Passed: " << (allPass ? "Yes" : "No") << "
";
    
    return 0;
}