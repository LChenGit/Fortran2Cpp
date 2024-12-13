#include <iostream>
#include <openacc.h>

void oacc1(int* a, int size) {
    // Parallel loop to increment elements of 'a'
    #pragma acc parallel loop
    for (int i = 0; i < size; i++) {
        a[i] += 1;
    }
}

int main() {
    int size = 5; 
    int* a = new int[size]; 

    for (int i = 0; i < size; i++) {
        a[i] = 0; // Initialize elements to 0
    }

    oacc1(a, size); // Call the subroutine to increment elements

    for (int i = 0; i < size; i++) {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    delete[] a; // Clean up dynamically allocated memory
    return 0;
}