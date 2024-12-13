#include <vector>

class MoColumn {
public:
    void computeColumn(int nz, std::vector<std::vector<double>>& q, std::vector<std::vector<double>>& t, int nproma) {
        for (int k = 0; k < nz; ++k) {
            for (int proma = 0; proma < nproma; ++proma) {
                if (t[proma][k] > 0.0) {
                    q[proma][k] /= t[proma][k];
                }
            }
        }
    }
};