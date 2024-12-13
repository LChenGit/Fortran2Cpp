#include <iostream>
#include <vector>
#include <cassert>

namespace tao_random_numbers {
    std::vector<int> s_buffer(10);
    int s_last = s_buffer.size();
}

namespace linalg {
    std::vector<float> diag(const std::vector<std::vector<float>>& a) {
        size_t min_dim = std::min(a.size(), a[0].size());
        std::vector<float> d(min_dim);
        for (size_t i = 0; i < min_dim; ++i) {
            d[i] = a[i][i];
        }
        return d;
    }
}

void run_tests() {
    using namespace tao_random_numbers;
    using namespace linalg;

    std::vector<std::vector<float>> x = { {1.0f, 2.0f}, {3.0f, 4.0f} };
    std::vector<float> expected_diag = {1.0f, 4.0f};
    int expected_s_last = 10;

    // Test s_last
    assert(s_last == expected_s_last);
    std::cout << "Test passed: s_last" << std::endl;

    // Test diag function
    std::vector<float> result_diag = diag(x);
    assert(result_diag == expected_diag);
    std::cout << "Test passed: diag" << std::endl;
}

int main() {
    std::cout << "Running C++ unit tests..." << std::endl;
    run_tests();
    std::cout << "C++ unit tests completed." << std::endl;
    return 0;
}