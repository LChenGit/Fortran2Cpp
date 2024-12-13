#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr(10);
    
    // Initialize the array
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1; // Matching Fortran's 1-based indexing
    }

    // Use OpenACC to increment each element in parallel
    #pragma acc data copy(arr[0:10])
    #pragma acc parallel loop
    for (int i = 0; i < 10; ++i) {
        arr[i] = arr[i] + 1;
    }

    // Print the results
    for (int i = 0; i < 10; ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    return 0;
}