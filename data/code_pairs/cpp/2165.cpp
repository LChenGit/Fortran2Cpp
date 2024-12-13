#include <iostream>
#include <array>

// Define the size of the arrays
constexpr int n = 1000;

// Declare the arrays globally to mimic the Fortran COMMON block
std::array<int, n> a;
std::array<int, n> b;
std::array<int, n> c;

void foo(int nr) {
    for (int ii = 0; ii < nr; ++ii) {
        c[ii] = a[ii] + b[ii] + 25;
    }
}

int main() {
    // Initialize arrays a and b with some test data
    for (int ii = 0; ii < n; ++ii) {
        a[ii] = ii;
        b[ii] = 2 * ii;
    }

    // Set the number of elements to process
    int nr = 10;

    // Call the function
    foo(nr);

    // Print the results
    std::cout << "Array c:" << std::endl;
    for (int ii = 0; ii < nr; ++ii) {
        std::cout << "c[" << ii << "] = " << c[ii] << std::endl;
    }

    return 0;
}