#include <iostream>
#include <numeric>
#include <vector>

void compute(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b, int& d) {
    const int size = 100;
    a.assign(size, std::vector<int>(size));
    b.assign(size, std::vector<int>(size));
    d = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            a[i][j] = 1;
            b[i][j] = 2;
            a[i][j] += b[i][j];
        }
    }

    for (int i = 0; i < size; ++i) {
        d += std::accumulate(a[i].begin(), a[i].end(), 0);
    }
}

void test() {
    std::vector<std::vector<int>> a, b;
    int d = 0;
    compute(a, b, d);
    std::cout << "Test sum: " << d << std::endl;
    if (d == 30000) {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
}

int main() {
    test();
    return 0;
}