#include <iostream>
#include <vector>
#include <cmath>
#include <omp.h>

namespace e_50_3_mod {

void init(std::vector<float>& v1, std::vector<float>& v2, int N) {
    for (int i = 0; i < N; ++i) {
        v1[i] = i + 2.0f;
        v2[i] = i - 3.0f;
    }
}

void check(const std::vector<float>& p, int N) {
    const float EPS = 0.00001f;
    for (int i = 0; i < N; ++i) {
        float diff = p[i] - (i + 2.0f) * (i - 3.0f);
        if (std::fabs(diff) > EPS) {
            std::cerr << "Check failed at index " << i << " with difference " << diff << std::endl;
            std::exit(1);
        }
    }
}

void vec_mult(int N) {
    std::vector<float> p(N), v1(N), v2(N);
    init(v1, v2, N);

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        p[i] = v1[i] * v2[i];
    }

    check(p, N);
}

} // namespace e_50_3_mod

int main() {
    e_50_3_mod::vec_mult(10);
    std::cout << "Test case 1 passed." << std::endl;
    e_50_3_mod::vec_mult(100);
    std::cout << "Test case 2 passed." << std::endl;
    e_50_3_mod::vec_mult(1000);
    std::cout << "Test case 3 passed." << std::endl;
    return 0;
}