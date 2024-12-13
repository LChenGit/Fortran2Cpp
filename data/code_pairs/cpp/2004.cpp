#include <iostream>
#include <vector>

int main() {
    const int n = 100;
    std::vector<std::vector<int>> a(n, std::vector<int>(n, 1)); // 2D vector with all elements initialized to 1
    int sum = 0;
    const int expected_sum = 10000;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum += a[i][j];
        }
    }

    if (sum == expected_sum) {
        std::cout << "Test Passed: Sum is correct." << std::endl;
    } else {
        std::cout << "Test Failed: Sum is incorrect." << std::endl;
    }

    return 0;
}