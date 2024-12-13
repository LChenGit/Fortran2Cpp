#include <iostream>
#include <vector>

namespace etrbk3_I {

    using DOUBLE = double;

    void etrbk3(int NM, int N, int NV, const DOUBLE* A, int M, DOUBLE* Z) {
        // Simple example: Copy A into the first row of Z
        if (NV <= M) {
            for (int i = 0; i < NV; ++i) {
                Z[i] = A[i];
            }
        }
    }
}