// main.cpp
#include <vector>
#include <iostream>

void initializeArrays(std::vector<int>& a, std::vector<int>& b, const int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = i * 2;
        b[i] = i * 4;
    }
}

void computeC(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& c, const int n) {
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    const int n = 1024;
    std::vector<int> a(n), b(n), c(n);

    initializeArrays(a, b, n);
    computeC(a, b, c, n);

    for (int i = 0; i < n; ++i) {
        if (c[i] != a[i] + b[i]) {
            std::cerr << "Mismatch at index " << i << std::endl;
            return 1;
        }
    }

    std::cout << "All tests passed successfully." << std::endl;
    return 0;
}