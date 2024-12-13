#include <iostream>
#include <array>
#include <numeric>
#include <algorithm>

int runTests();

int main() {
    int status = runTests();
    if (status == 0) {
        std::cout << "C++: Test Passed" << std::endl;
    } else {
        std::cout << "C++: Test Failed with status: " << status << std::endl;
    }
    return 0;
}

int runTests() {
    std::array<std::array<int, 4>, 4> m = {{{1, 2, 3, 4},
                                            {5, 6, 7, 8},
                                            {9, 10, 11, 12},
                                            {13, 14, 15, 16}}};
    int sevens = std::accumulate(m.begin(), m.end(), 0, [](int acc, const std::array<int, 4>& row) {
        return acc + std::count(row.begin(), row.end(), 7);
    });

    std::array<int, 4> odd = {};
    for (int i = 0; i < 4; ++i) {
        odd[i] = std::count_if(m[i].begin(), m[i].end(), [](int x) { return x % 2 == 1; });
    }

    int even = std::accumulate(m.begin(), m.end(), 0, [](int acc, const std::array<int, 4>& row) {
        return acc + std::count_if(row.begin(), row.end(), [](int x) { return x % 2 == 0; });
    });

    if (sevens != 1) return 1;
    if (!std::equal(odd.begin(), odd.end(), std::array<int, 4>{2, 2, 2, 2}.begin())) return 2;
    if (even != 8) return 3;

    return 0; // Test Passed
}