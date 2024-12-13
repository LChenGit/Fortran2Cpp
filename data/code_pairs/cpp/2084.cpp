#include <iostream>
#include <vector>
#include <cstdlib> // For exit()

int calculateSumAndCheck(const int N) {
    std::vector<int> a(N); // Using vector for dynamic array allocation
    
    // Filling the array
    for(int i = 0; i < N; ++i) {
        a[i] = i + 1; // Adjusting for 0-based indexing in C++
    }
    
    // Summing the array elements
    int s = 0;
    for(int i = 0; i < N; ++i) {
        s += a[i];
    }
    
    // Checking the sum and determining the result
    if(s != 500500) {
        return -1;
    }
    return 0;
}

int main() {
    int result = calculateSumAndCheck(1000);
    
    // Outputting the result
    if(result == 0) {
        std::cout << "PASS" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
        exit(1); // Exiting with an error code
    }
    
    return 0;
}