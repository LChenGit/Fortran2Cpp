#include <iostream>

int main() {
    const int size = 4;
    int tt[size][size] = {0}; // Initialize a 4x4 matrix with zeros

    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(i == 1 && j == 1) {
                tt[i][j] = 5; // Modify the element at (1,1)
            }
        }
    }

    std::cout << "C++ Matrix Output:" << std::endl;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            std::cout << tt[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}