#include <vector>

class MoColumn {
public:
    void compute_column(int nz, std::vector<float>& t, std::vector<float>& q) {
        float c = 5.345f;
        c = c * c;

        for (int k = 1; k < nz; ++k) { // Adjusted for 0-based indexing
            t[k] = c * (k + 1); // k+1 to adjust the calculation for 0-based indexing
            q[k] = q[k - 1] + t[k] * c;
        }

        if (q[nz-1] > 0.0f) { // Adjusted for 0-based indexing
            q[nz-1] = q[nz-1] * c; // Adjusted for 0-based indexing
        }
    }
};