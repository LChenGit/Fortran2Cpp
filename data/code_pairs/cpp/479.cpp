#include <vector>
#include <cassert>
#include <iostream>

class Matrix {
public:
    int rows;
    int columns;
    std::vector<std::vector<double>> data; // Assuming the data type is double. Adjust if necessary.

    Matrix(int r, int c) : rows(r), columns(c), data(r, std::vector<double>(c, 0.0)) {
        // The matrix is now initialized with 0.0 for each element
    }
};