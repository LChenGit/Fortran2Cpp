// workshare.cpp
#include <iostream>
#include <vector>
#include <omp.h>

void workshare(std::vector<std::vector<float>>& aa, std::vector<std::vector<float>>& bb, 
               std::vector<std::vector<float>>& cc, std::vector<std::vector<float>>& dd, 
               std::vector<std::vector<float>>& ee, std::vector<std::vector<float>>& ff, int n) {
    // Parallel loop equivalent
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        std::cout << "omp workshare" << std::endl;
    }

    // Critical section for array copy
    #pragma omp critical
    {
        #pragma omp single
        {
            aa = bb;
        }
    }

    // Parallel section for array copy
    #pragma omp parallel
    {
        #pragma omp single
        {
            cc = dd;
        }
    }

    // Direct copy outside of parallel region
    ee = ff;
}

int main() {
    int n = 4;
    std::vector<std::vector<float>> aa(n, std::vector<float>(n)),
                                    bb(n, std::vector<float>(n)),
                                    cc(n, std::vector<float>(n)),
                                    dd(n, std::vector<float>(n)),
                                    ee(n, std::vector<float>(n)),
                                    ff(n, std::vector<float>(n));

    // Initialize matrices for testing
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            bb[i][j] = (i * n) + j + 1;
            dd[i][j] = (i * n) + j + 1 + n*n;
            ff[i][j] = (i * n) + j + 1 + 2*n*n;
        }
    }

    workshare(aa, bb, cc, dd, ee, ff, n);

    // Verification (optional, based on your verification strategy)
    // std::cout << "Verification skipped" << std::endl;

    return 0;
}