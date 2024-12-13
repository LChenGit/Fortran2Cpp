#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // For std::fixed and std::setprecision

void ranstd(std::vector<double>& x) {
    int n = x.size();
    if (n <= 1) return;
    
    double sum1 = 0.0;
    double sum2 = 0.0;
    
    for (int i = 0; i < n; ++i) {
        sum1 += x[i];
        sum2 += x[i] * x[i];
    }
    
    sum1 /= n;
    sum2 /= n;
    
    if (sum2 > (sum1 * sum1)) {
        sum2 = 1.0 / sqrt(sum2 - sum1 * sum1);
    } else {
        std::cerr << "ranstd: n,sum2=" << n << "," << sum2 << " cannot standardize variance\n";
        sum2 = 1.0;
    }
    
    sum1 = -sum1 * sum2;
    
    for (int i = 0; i < n; ++i) {
        x[i] = sum1 + sum2 * x[i];
    }
}

void printVector(const std::vector<double>& vec) {
    for (const auto& val : vec) {
        std::cout << std::fixed << std::setprecision(4) << val << " ";
    }
    std::cout << std::endl;
}

void testRanstd(std::vector<double> vec) {
    std::cout << "Original Vector: ";
    printVector(vec);
    
    ranstd(vec);

    std::cout << "After ranstd: ";
    printVector(vec);
    std::cout << std::endl;
}

int main() {
    std::cout << "Test Case 1" << std::endl;
    testRanstd({2.0, 4.0, 4.0, 4.0, 5.0});

    std::cout << "Test Case 2" << std::endl;
    testRanstd({1.0, 2.0, 3.0});

    return 0;
}