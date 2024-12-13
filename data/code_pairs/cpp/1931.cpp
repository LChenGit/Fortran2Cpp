#include <iostream>
#include <cstdlib> // For std::abort()

const int size = 100;

void kernels(int* array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1; // Adjusting for 0-based indexing in C++
    }
}

int main() {
    int array[size];

    kernels(array, size);
    for (int i = 0; i < size; ++i) {
        if (array[i] != i + 1) { // Test failed
            std::cerr << "Kernels Test FAILED." << std::endl;
            std::abort();
        }
    }
    std::cout << "Kernels Test PASSED." << std::endl;

    return 0;
}