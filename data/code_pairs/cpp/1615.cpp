#include <iostream>
#include <vector>
#include <cmath>

class SchmitI {
public:
    void schmit(std::vector<std::vector<double>>& U, int N, int NDIM) {
        double colNorm;
        for (int j = 0; j < NDIM; ++j) {
            colNorm = 0.0;
            for (int i = 0; i < NDIM; ++i) {
                colNorm += U[i][j] * U[i][j];
            }
            colNorm = std::sqrt(colNorm);
            for (int i = 0; i < NDIM; ++i) {
                U[i][j] /= colNorm;
            }
        }
    }
};

int main() {
    SchmitI schmitI;
    std::vector<std::vector<double>> U = {{1.0, 2.0, 3.0},
                                          {2.0, 3.0, 4.0},
                                          {3.0, 4.0, 5.0}};
    schmitI.schmit(U, 3, 3);
    std::cout << "Normalized Matrix U:" << std::endl;
    for (const auto& row : U) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}