#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> fun(int n);

int main() {
    std::vector<int> b(2); // Vector of size 2
    b = fun(b.size()); // Populate b using the fun function
    
    // Assert to check if b is correctly initialized
    assert(b[0] == 1 && b[1] == 2 && "Test failed: b is not correctly initialized.");
    
    // If the program reaches this point, the test has passed
    std::cout << "Test passed: b is correctly initialized." << std::endl;
    
    return 0;
}

std::vector<int> fun(int n) {
    std::vector<int> result(n); // Result vector of size n
    
    for (int i = 0; i < n; ++i) {
        result[i] = i + 1;
    }
    
    return result;
}