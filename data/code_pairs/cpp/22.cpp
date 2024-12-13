#include <vector>

namespace mo_column {

class ColumnComputer {
public:
    static void compute_column(int nz, std::vector<std::vector<double>>& q, std::vector<std::vector<double>>& t, int nproma) {
        double c = 5.345;

        for (int proma = 0; proma < nproma; ++proma) {
            for (int k = 1; k < nz; ++k) { // Adjusted for 0-based indexing
                t[k][proma] = c * (k + 1); // Fortran k is equivalent to k + 1 in C++
                q[k][proma] = q[k - 1][proma] + t[k][proma] * c;
            }
            q[nz - 1][proma] *= c;
        }
    }

    static void compute(int nz, std::vector<std::vector<double>>& q, int nproma) {
        std::vector<std::vector<double>> t(nz, std::vector<double>(nproma, 0.0)); // Initialize t with zeros
        compute_column(nz, q, t, nproma);
    }
};

} // namespace mo_column