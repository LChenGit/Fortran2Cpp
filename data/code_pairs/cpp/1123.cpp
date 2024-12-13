#include <vector>
#include <iostream>

class mo_column {
public:
    static void compute_column(int nz, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, int nproma) {
        for (int i = 0; i < nz; ++i) {
            for (int j = 0; j < nproma; ++j) {
                t[i][j] += 1.0f;
                q[i][j] += 1.0f;
            }
        }
    }
};