#include <iostream>

int main() {
    int* a = nullptr; // Pointer initialization to a null pointer.
    int sum = 0;

    // Allocate memory for 1000 integers.
    a = new int[1000];
    
    // Initialize array
    for (int i = 0; i < 1000; ++i) {
        a[i] = 1;
    }

    // Calculate sum
    for (int i = 0; i < 1000; ++i) {
        sum += a[i];
    }

    // Expected sum is 1000
    if (sum == 1000) {
        std::cout << "Test Passed!" << std::endl;
    } else {
        std::cout << "Test Failed!" << std::endl;
    }

    // Deallocate the allocated memory.
    delete[] a;

    return 0;
}