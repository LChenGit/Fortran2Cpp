#include <iostream>
#include <cstdlib> // For std::abort()

#define N 1024

int main() {
    int a[N], b[N], c[N];
    bool test_passed = true;

    // Initialize arrays a and b
    for (int i = 0; i < N; ++i) {
        a[i] = i * 2;
        b[i] = i * 4;
    }

    // Parallel section for computing c = a + b
    #pragma acc kernels copyin(a[0:N-1],b[0:N-1]) copyout(c[0:N-1])
    for (int ii = 0; ii < N; ++ii) {
        c[ii] = a[ii] + b[ii];
    }

    // Verification
    for (int i = 0; i < N; ++i) {
        if (c[i] != a[i] + b[i]) {
            test_passed = false;
            break; // Exit the loop on the first failed test
        }
    }

    // Check if all tests passed
    if (test_passed) {
        std::cout << "All tests passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }

    return 0;
}