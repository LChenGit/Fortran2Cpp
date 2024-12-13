#include <vector>
#include <iostream>
#include <omp.h>

void compute_column(int nz, std::vector<std::vector<std::vector<float>>>& q, std::vector<std::vector<std::vector<float>>>& t, int nx, int ny) {
    float c = 5.345f;
    float d;

    #pragma omp target
    #pragma omp teams
    #pragma omp distribute collapse(2)
    for(int j = 0; j < ny; ++j) {
        for(int i = 0; i < nx; ++i) {
            c = 5.345f;
            for(int k = 1; k < nz; ++k) { // Adjusted for zero-based indexing
                t[i][j][k] = c * (k + 1); // Adjust for zero-based indexing by adding 1 to k
                d = t[i][j][k] + c;
                q[i][j][k] = q[i][j][k - 1] + t[i][j][k] * c + d;
            }
            q[i][j][nz - 1] *= c; // Adjusted for zero-based indexing
        }
    }
}

int main() {
    int nx = 10, ny = 10, nz = 10;
    std::vector<std::vector<std::vector<float>>> q(nx, std::vector<std::vector<float>>(ny, std::vector<float>(nz, 0)));
    std::vector<std::vector<std::vector<float>>> t(nx, std::vector<std::vector<float>>(ny, std::vector<float>(nz, 0)));

    compute_column(nz, q, t, nx, ny);

    std::cout << "Sample output q[4][4][4]: " << q[4][4][4] << std::endl;

    return 0;
}