#include <iostream>
#include <cstdlib> // For exit()
#include <cassert> // For assert()

int main() {
    int array[2][3] = {{11, 12, 13}, {21, 22, 23}};

    // Assertions to verify the initialization (Optional, as we're manually checking)
    assert(array[0][0] == 11);
    assert(array[0][1] == 12);
    assert(array[0][2] == 13);
    assert(array[1][0] == 21);
    assert(array[1][1] == 22);
    assert(array[1][2] == 23);

    // Manual check to match Fortran output
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "array(" << (i+1) << ", " << (j-1) << ") = " << array[i][j] << std::endl;
        }
    }

    std::cout << "All tests passed." << std::endl;

    return 0; // Successful execution
}