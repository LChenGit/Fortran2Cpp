#include <iostream>
#include <cstdlib>

// Function definition
int edg(int l, int k, int e[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (e[i][l] == k) {
            return i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
        }
    }

    std::cerr << "0***error in function edg***" << std::endl;
    std::cerr << "***elements not adjacent***" << std::endl;
    std::exit(201);
}

int main() {
    // Initialize test data
    int e[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Test case 1: adjacent elements
    int l = 0; // equivalent to 1 in Fortran
    int k = 4;
    int result = edg(l, k, e);
    std::cout << "Test Case 1 Result: " << result << std::endl;

    // Test case 2: non-adjacent elements, should trigger error messages
    l = 1; // equivalent to 2 in Fortran
    k = 10;
    // Note: No result is printed for Test Case 2 as the program exits due to std::exit(201);
    edg(l, k, e);

    return 0;
}