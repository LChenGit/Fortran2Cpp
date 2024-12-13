#include <vector>
#include <iostream>

// Array2D definition
template<typename T>
struct Array2D {
    size_t rows, cols;
    std::vector<T> data;

    Array2D(size_t rows, size_t cols, T initial_value = T()) : rows(rows), cols(cols), data(rows * cols, initial_value) {}

    T& operator()(size_t row, size_t col) {
        return data[(row - 1) * cols + (col - 1)]; // 1-based indexing
    }

    const T& operator()(size_t row, size_t col) const {
        return data[(row - 1) * cols + (col - 1)]; // 1-based indexing for const objects
    }
};