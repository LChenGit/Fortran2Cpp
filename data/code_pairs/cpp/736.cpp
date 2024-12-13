#include <iostream>
#include <cstdlib> // For std::abort()
#include <cassert> // For assert()

void kernel(int lo, int hi, float a[], float b[], float c[]);

int main() {
    const int n = 20;
    float a[n], b[n], c[n];

    // Initialize arrays
    for (int i = 0; i < n; i++) {
        a[i] = 1.0f;
        b[i] = 2.0f;
        c[i] = 3.0f;
    }

    // Call the kernel function
    kernel(0, n, a, b, c);

    // Test to ensure all elements of c are equal to 1
    for (int i = 0; i < n; i++) {
        assert(c[i] == 1.0f);
    }

    std::cout << "Test passed: All elements of c are equal to 1." << std::endl;

    return 0; // Success
}

void kernel(int lo, int hi, float a[], float b[], float c[]) {
    for (int i = lo; i < hi; i++) {
        b[i] = a[i];
    }
    for (int i = lo; i < hi; i++) {
        c[i] = b[i];
    }
}