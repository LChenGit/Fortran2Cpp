#include <iostream>
#include <numeric> // For std::accumulate

int main() {
    const int size = 10000;
    int a[size], b[size];

    for (int i = 0; i < size; ++i) {
        a[i] = 1;
        b[i] = 2;
    }

    for (int i = 0; i < size; ++i) {
        a[i] += b[i];
    }

    int d = std::accumulate(a, a + size, 0);

    // Simple unit test to check the sum
    std::cout << "Computed sum = " << d << std::endl;
    if (d == 30000) {
        std::cout << "Test passed: sum is correct." << std::endl;
    } else {
        std::cout << "Test failed: sum is incorrect." << std::endl;
    }

    return 0;
}