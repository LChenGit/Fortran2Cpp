#include <vector>
#include <algorithm>

void b4step2(
    int mbc, int mx, int my, int meqn,
    std::vector<double>& q, double xlower, double ylower, 
    double dx, double dy, double t, double dt, 
    int maux, std::vector<double>& aux)
{
    if (t > 1.0) {
        for (int k = 0; k < maux; ++k) {
            if (k == 12) { // Adjusted for 0-based indexing
                for (int j = 0; j < my + 2 * mbc; ++j) {
                    for (int i = 0; i < mx + 2 * mbc; ++i) {
                        aux[k * (mx + 2 * mbc) * (my + 2 * mbc) + j * (mx + 2 * mbc) + i] = 0.0;
                    }
                }
            }
        }
    }
}