#include <vector>
#include <iostream>

std::vector<std::vector<int>> reshape(const std::vector<int>& vect, int rows, int cols) {
    std::vector<std::vector<int>> reshaped(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            reshaped[i][j] = vect[i * cols + j];
        }
    }
    return reshaped;
}

int main() {
    int r = 2, nb = 4;
    std::vector<int> vect(nb * r, 1);
    auto reshaped = reshape(vect, r, nb);
    // The main function here is primarily for demonstration.
    // The unit test for validation is separate.
    return 0;
}