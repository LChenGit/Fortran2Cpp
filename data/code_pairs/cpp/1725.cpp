#include <vector>

void calcPel(int ne, std::vector<std::vector<double>>& vel, const std::vector<double>& b, int nef) {
    for (int i = 0; i < ne; ++i) {
        vel[i][4] += b[i];
    }
}