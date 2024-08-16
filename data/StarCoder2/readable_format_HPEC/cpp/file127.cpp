#include <iostream>
#include <omp.h>

int main() {
    const int len = 1000;
    int a[len];

    // Initialize the array
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Adjusted for 0-based indexing
    }

    // Parallel loop to update array elements
    #pragma omp parallel for
    for (int i = 0; i < len - 1; ++i) {
        a[i] = a[i + 1] + 1;
    }

    // Print the result
    std::cout << "a[500-1]=" << a[500 - 1] << std::endl; // Adjusted for 0-based indexing and output

    return 0;
}