#include <vector>

// Assuming beta is declared somewhere globally
extern double beta;

void qinit(int maxmx, int meqn, int mbc, int mx, double xlower, double dx, std::vector<std::vector<double>>& q, int maux, std::vector<std::vector<double>>& aux) {
    double ql = 0.13;
    double qr = 0.1;

    for (int i = 0; i < mx; ++i) {
        double xcell = xlower + (i + 0.5) * dx; // Adjusted for 0-based indexing
        if (xcell < 0.0) {
            q[i][0] = ql; // Adjusted for 0-based indexing in both dimensions
        } else {
            q[i][0] = qr; // Adjusted for 0-based indexing in both dimensions
        }
    }
}