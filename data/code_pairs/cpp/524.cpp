#include <cmath>

class Powell {
public:
    void trsapp(int n, const double* d, double& crvmin) {
        crvmin = 0.0;
        for (int i = 0; i < n; ++i) {
            crvmin += std::pow(d[i], 2);
        }
    }
};