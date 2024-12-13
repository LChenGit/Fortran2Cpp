#include <vector>

namespace mo_column {
    
    void compute_column(int nz, std::vector<float>& q, std::vector<float>& t, float& z) {
        float c = 5.345f;
        for (int k = 1; k < nz; ++k) {
            t[k] = c * (k + 1); // Adjusted to match Fortran's 1-based indexing in the computation
            q[k] = q[k - 1] + t[k] * c;
        }
        q[nz - 1] *= c; // -1 to adjust for 0-based indexing in C++
    }

    void compute(int nz, std::vector<float>& q, std::vector<float>& t, float& z) {
        compute_column(nz, q, t, z);
    }
}