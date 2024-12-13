#ifndef MOCOLUMN_H
#define MOCOLUMN_H

#include <vector>

class TyColumn {
public:
    void compute_column(int nz, std::vector<std::vector<double>>& q, std::vector<std::vector<double>>& t, int nproma) {
        for (int i = 0; i < nz; ++i) {
            for (int j = 0; j < nproma; ++j) {
                q[i][j] *= 2.0;
                t[i][j] += 10.0;
            }
        }
    }
};

#endif // MOCOLUMN_H