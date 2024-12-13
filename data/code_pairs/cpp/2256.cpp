#include <iostream>
#include <vector>
#include <cstdlib>

// Adjusted to correct the mapping issue from the previous version
void sub(int N, std::vector<std::vector<double>>& u) {
    u[N][2*N] = 0.0; // Corrected indexing to match Fortran's behavior
}

int main() {
    const int N = 10;
    std::vector<std::vector<double>> a(2 * N + 1, std::vector<double>(2 * N + 1, 1.0));

    sub(N, a);

    // Adjusted the condition to correctly check the modified element
    if (a[N][2 * N] != 0.0) {
        std::cout << "Test failed: a[N][2 * N] is not 0.0" << std::endl;
        std::abort();
    } else {
        std::cout << "Test passed: a[N][2 * N] is 0.0" << std::endl;
    }

    return 0;
}