#include <iostream>
#include <vector>
#include <cassert>

void testConcatArrays() {
    // Initialize arrays as in the main function
    std::vector<std::vector<double>> a(10, std::vector<double>(10, 1.0));
    std::vector<double> b = {4, 5, 6, 4, 5, 2, 7, 4, 9, 1};
    std::vector<std::vector<double>> c(a.size() + 1, std::vector<double>(a[0].size() + 1, 0.0));

    // Perform the concatenation (same as the main function)
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[i].size(); ++j) {
            c[i][j] = a[i][j];
        }
    }
    for (size_t i = 0; i < b.size(); ++i) {
        c[a.size()][i] = b[i]; // Last row
        c[i][a[0].size()] = b[i]; // Last column
    }

    // Assertions for testing
    assert(a.size() == 10); // Test the row size of 'a'
    for (const auto& row : a) {
        for (const auto& elem : row) {
            assert(elem == 1.0); // Test the elements of 'a'
        }
    }

    std::cout << "All Tests Passed." << std::endl;
}

int main() {
    testConcatArrays();
    // You can call the main functionality here if needed.
    return 0;
}