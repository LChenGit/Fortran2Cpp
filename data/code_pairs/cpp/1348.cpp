#include <vector>

void clawpack46SetAux(int mbc, int mx, int my, int mz,
                      double xlower, double ylower, double zlower,
                      double dx, double dy, double dz,
                      int maux,
                      std::vector<std::vector<std::vector<std::vector<double>>>>& aux) {
    aux.resize(mx + 2 * mbc);
    for (int i = 0; i < mx + 2 * mbc; ++i) {
        aux[i].resize(my + 2 * mbc);
        for (int j = 0; j < my + 2 * mbc; ++j) {
            aux[i][j].resize(mz + 2 * mbc);
            for (int k = 0; k < mz + 2 * mbc; ++k) {
                aux[i][j][k].resize(maux);
                // Example initialization
                for (int l = 0; l < maux; ++l) {
                    aux[i][j][k][l] = (i + j + k + l); // Simple value assignment for demonstration
                }
            }
        }
    }
}