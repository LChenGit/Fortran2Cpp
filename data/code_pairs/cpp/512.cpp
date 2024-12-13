#include <iostream>
#include <cstdlib> // For std::abort()
#include <cassert>

void test_code() {
    int i, j, k, l, r;
    int a[30];
    int q[30];
    int* p = nullptr;

    for (i = 0; i < 30; ++i) {
        a[i] = 1;
        q[i] = 1;
    }

    p = &q[0];

    r = 0;
    j = 10;
    k = 20;

    #pragma omp simd safelen(8) reduction(+:r) linear(j, k:2) private(l) aligned(p:4)
    for (i = 0; i < 30; ++i) {
        l = j + k + a[i] + p[i];
        r += l;
        j += 2;
        k += 2;
    }

    assert(r == 2700 && j == 70 && k == 80);
}

int main() {
    test_code();
    std::cout << "Test passed." << std::endl;
    return 0;
}