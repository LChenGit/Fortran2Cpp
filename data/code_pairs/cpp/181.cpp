#include <iostream>
#include <vector>
#include <cmath> // For pow()
#include <cassert> // For assert()

// Function prototype
void fsub(const std::vector<double>& x, int n, std::vector<double>& f);

int main() {
    std::vector<double> y = {2.0, 3.0, 7.0}; 
    int n = y.size(); 
    std::vector<double> z(n); 

    fsub(y, n, z); 

    // Unit test
    std::vector<double> expected_z = {4.0, 9.0, 49.0};
    for (int i = 0; i < n; i++) {
        assert(z[i] == expected_z[i]);
    }
    std::cout << "Test Passed." << std::endl;

    return 0;
}

void fsub(const std::vector<double>& x, int n, std::vector<double>& f) {
    for (int i = 0; i < n; i++) {
        f[i] = std::pow(x[i], 2); 
    }
}