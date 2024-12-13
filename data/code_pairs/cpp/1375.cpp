#include <iostream>
#include <vector>
#include <cstdlib>

void test_initial_assignment(const std::vector<float>& a, const std::vector<float>& b) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != 3.0f || b[i] != 0.0f) {
            std::cerr << "Test failed: Initial assignment to a or b is incorrect." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
    std::cout << "Test passed: Initial assignment to a and b is correct." << std::endl;
}

void test_parallel_assignment(const std::vector<float>& b) {
    for (float val : b) {
        if (val != 3.0f) {
            std::cerr << "Test failed: Parallel assignment to b from a is incorrect." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
    std::cout << "Test passed: Parallel assignment to b from a is correct." << std::endl;
}

void test_final_result(const std::vector<float>& a, const std::vector<float>& b) {
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != 5.0f || b[i] != 5.0f) {
            std::cerr << "Test failed: Final values of a or b are incorrect." << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
    std::cout << "Test passed: Final values of a and b are correct." << std::endl;
}

int main() {
    const int N = 8;
    std::vector<float> a(N), b(N);

    std::fill(a.begin(), a.end(), 3.0f);
    std::fill(b.begin(), b.end(), 0.0f);

    test_initial_assignment(a, b);

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        b[i] = a[i];
    }

    test_parallel_assignment(b);

    std::fill(a.begin(), a.end(), 5.0f);
    std::fill(b.begin(), b.end(), 1.0f);

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        b[i] = a[i];
    }

    test_final_result(a, b);

    return 0;
}