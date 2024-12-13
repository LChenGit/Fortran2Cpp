#include <iostream>
#include <vector>
#include <complex>

using std::vector;
using std::complex;

using Complex = complex<double>;

void me08a(vector<vector<Complex>>& A, vector<Complex>& ALPHA, vector<Complex>& BETA, int N, int IA, vector<Complex>& Q) {
    for (int i = 0; i < IA; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] *= ALPHA[0];
        }
    }
    Q[0] += BETA[0];
}