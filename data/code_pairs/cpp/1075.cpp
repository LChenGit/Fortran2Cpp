#include <iostream>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::fill_n

// Declaration of compute_column - assume external linkage
extern void compute_column(int arg1, int nz, float q[][60], float t[][60], int nproma);

// Dummy implementation of compute_column for demonstration. Replace as necessary.
void compute_column(int arg1, int nz, float q[][60], float t[][60], int nproma) {
    for (int i = 0; i < nproma; i++) {
        for (int j = 0; j < nz; j++) {
            q[i][j] = 1.0f; // Assuming modifications made by compute_column
            t[i][j] = 2.0f; // Assuming modifications made by compute_column
        }
    }
}

int main() {
    const int nproma = 20;
    const int nz = 60;
    float q[nproma][nz];
    float t[nproma][nz];

    // Initialize arrays
    for (int i = 0; i < nproma; ++i) {
        std::fill_n(q[i], nz, 0.0f);
        std::fill_n(t[i], nz, 0.0f);
    }

    // Call compute_column
    compute_column(4, nz, q, t, nproma);

    // Compute sums
    float sum_q = 0.0f, sum_t = 0.0f;
    for (int i = 0; i < nproma; ++i) {
        sum_q += std::accumulate(q[i], q[i]+nz, 0.0f);
        sum_t += std::accumulate(t[i], t[i]+nz, 0.0f);
    }

    std::cout << "Sum of q: " << sum_q << std::endl;
    std::cout << "Sum of t: " << sum_t << std::endl;

    return 0;
}