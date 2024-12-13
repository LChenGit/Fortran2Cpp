#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

void printMatrix(const std::string& name, const std::vector<std::vector<float>>& matrix) {
    std::cout << name << ":" << std::endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(3) << elem;
        }
        std::cout << std::endl;
    }
}

float f(int i, int j) {
    return static_cast<float>(i * j);
}

void callTest(int nrows, int ncols) {
    std::vector<std::vector<float>> array6(nrows, std::vector<float>(ncols));
    std::vector<std::vector<float>> array7(nrows, std::vector<float>(ncols));

    for (int r = 0; r < nrows; ++r) {
        for (int c = 0; c < ncols; ++c) {
            array6[r][c] = static_cast<float>((r + 1) * (c + 1));
        }
    }
    printMatrix("array6", array6);

    for (int r = 0; r < nrows; ++r) {
        for (int c = 0; c < ncols; ++c) {
            array7[r][c] = f(r + 1, c + 1) * 2.0f;
        }
    }
    printMatrix("array7", array7);

    for (int r = 0; r < nrows; ++r) {
        for (int c = 0; c < ncols; ++c) {
            array7[r][c] = array6[r][c] * 2.0f;
        }
    }
    printMatrix("array7", array7);
}

int main() {
    callTest(10, 20);
    return 0;
}