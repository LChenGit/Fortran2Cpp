#include <cstdint>
#include <iostream>
#include <vector>

void nidentll(const std::int64_t* x, std::int64_t px, int n, int& id);

int main() {
    std::vector<std::int64_t> x = {1, 3, 5, 7, 9};
    std::vector<std::int64_t> test_values = {1, 5, 9, 11};
    std::vector<int> expected_ids = {1, 3, 5, 0}; // Adjusting for 0-based indexing in expected results

    for (size_t i = 0; i < test_values.size(); ++i) {
        int id = -1; // Adjusted initialization for 0-based index
        nidentll(x.data(), test_values[i], x.size(), id);
        std::cout << "Test " << i + 1 << ": px=" << test_values[i] << " Expected ID=" << expected_ids[i]
                  << " Got ID=" << id+1 << std::endl; // Adjusted output for 1-based index comparison
        if ((id+1) == expected_ids[i]) {
            std::cout << "Test Passed" << std::endl;
        } else {
            std::cout << "Test Failed" << std::endl;
        }
    }
    return 0;
}

void nidentll(const std::int64_t* x, std::int64_t px, int n, int& id) {
    id = -1; // Adjusted initialization for 0-based index
    if (n == 0) return;
    int n2 = n;
    while (true) {
        int m = (n2 + id + 1) / 2; // Adjusted calculation for 0-based index
        if (px >= x[m]) {
            id = m;
        } else {
            n2 = m;
        }
        if ((n2 - id) == 1) break;
    }
    if (id >= 0 && x[id] != px) id = -1; // Corrected: Check if value is found, adjusted for 0-based index
}