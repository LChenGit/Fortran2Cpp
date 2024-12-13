#include <iostream>
#include <vector>
#include <omp.h>

int foo(const std::vector<int>& a, std::vector<int>& b, int n) {
    int r = 0;
    
    b[0] = a[0];
    r += a[0];
    for (int i = 1; i < n; ++i) {
        b[i] = b[i - 1] + a[i];
        r += a[i];
    }
    
    return r;
}

int main() {
    int n = 5; // Example size
    std::vector<int> a = {1, 2, 3, 4, 5}; // Example input
    std::vector<int> b(n); // Output vector
    
    int result = foo(a, b, n);
    
    std::cout << "Sum: " << result << std::endl;
    std::cout << "B: ";
    for (int i : b) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}