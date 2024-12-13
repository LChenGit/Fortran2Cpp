#include <iostream>
#include <vector>

int main() {
    const int rows = 2;
    const int cols = 3;
    std::vector<std::vector<float>> a(rows, std::vector<float>(cols));

    // Fill the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            a[i][j] = 10 * (i + 1) + (j + 1);
        }
    }

    // Print the entire matrix in the specified order
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            std::cout << a[i][j] << " ";
        }
    }
    std::cout << std::endl;

    // Print the first row
    for (int j = 0; j < cols; ++j) {
        std::cout << a[0][j] << " ";
    }
    std::cout << std::endl;

    // Print the first column
    for (int i = 0; i < rows; ++i) {
        std::cout << a[i][0] << " ";
    }
    std::cout << std::endl;

    return 0;
}